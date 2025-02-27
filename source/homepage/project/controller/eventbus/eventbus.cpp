#include "eventbus.h"

EventBus& EventBus::getInstance()
{
    static EventBus instance;
    return instance;
}

EventBus::EventBus(QObject* parent) : QObject(parent)
{
}

EventBus::~EventBus()
{
}

void EventBus::registerEvent(const QString& eventName)
{
    if (!m_subscribers.contains(eventName)) {
        m_subscribers[eventName] = QSet<QPair<QObject*, const char*>>();
    }
}

void EventBus::unregisterEvent(const QString& eventName)
{
    m_subscribers.remove(eventName);
}

void EventBus::subscribe(const QString& eventName, QObject* receiver, const char* method)
{
    if (!m_subscribers.contains(eventName)) {
        registerEvent(eventName);
    }

    m_subscribers[eventName].insert(qMakePair(receiver, method));
}

void EventBus::unsubscribe(const QString& eventName, QObject* receiver)
{
    if (!m_subscribers.contains(eventName)) {
        return;
    }

    QSet<QPair<QObject*, const char*>> &subscribers = m_subscribers[eventName];
    QMutableSetIterator<QPair<QObject*, const char*>> i(subscribers);
    while (i.hasNext()) {
        if (i.next().first == receiver) {
            i.remove();
        }
    }
}

void EventBus::publish(const QString& eventName, const QVariant& data)
{
    if (!m_subscribers.contains(eventName)) {
        return;
    }

    qDebug() << "Publishing event:" << eventName;
    for (const auto& subscriber : m_subscribers[eventName]) {
        QMetaObject::invokeMethod(subscriber.first, subscriber.second,
                                  Qt::AutoConnection, Q_ARG(QVariant, data));
    }
}
