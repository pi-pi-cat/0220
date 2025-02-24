#ifndef PROJECTMEDIATOR_H
#define PROJECTMEDIATOR_H

#include <QObject>

class ProjectMediator : public QObject
{
    Q_OBJECT
public:
    explicit ProjectMediator(QObject *parent = nullptr);

signals:

};

#endif // PROJECTMEDIATOR_H
