#ifndef DEVICELOGIC_H
#define DEVICELOGIC_H

#include <QObject>

class DeviceLogic : public QObject
{
    Q_OBJECT
public:
    explicit DeviceLogic(QObject *parent = nullptr);

signals:

};

#endif // DEVICELOGIC_H
