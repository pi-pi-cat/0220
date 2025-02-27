#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <QObject>
#include <QMap>
#include <QSet>
#include <QPair>
#include <QVariant>
#include <QDebug>
#include "global_h.h"

// 事件总线类 - 用于不同Mediator之间的通信
class PROJECT_EXPORT EventBus : public QObject
{
    Q_OBJECT
public:
    // 单例模式获取EventBus实例
    static EventBus& getInstance();

    // 注册事件
    void registerEvent(const QString& eventName);

    // 取消注册事件
    void unregisterEvent(const QString& eventName);

    // 订阅事件
    void subscribe(const QString& eventName, QObject* receiver, const char* method);

    // 取消订阅事件
    void unsubscribe(const QString& eventName, QObject* receiver);

    // 发布事件
    void publish(const QString& eventName, const QVariant& data = QVariant());

private:
    // 私有构造函数，确保只能通过getInstance获取实例
    explicit EventBus(QObject* parent = nullptr);
    ~EventBus();

    // 存储事件订阅信息
    QMap<QString, QSet<QPair<QObject*, const char*>>> m_subscribers;
};

#endif // EVENTBUS_H
