#ifndef DEVICELISTMODEL_H
#define DEVICELISTMODEL_H

#include <QAbstractListModel>
#include "global_h.h"
#include "../internal/deviceinfo.h"

class PROJECT_EXPORT DeviceListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    // 自定义角色
    enum DeviceRoles {
        NameRole = Qt::UserRole + 1,
        DisplayNameRole,
        CreationTimeRole,
        ModificationTimeRole,
        DescriptionRole,
        StatusRole
    };
    explicit DeviceListModel(QObject *parent = nullptr);

    // QAbstractListModel 接口实现
    int rowCount(const QModelIndex& parent = QModelIndex()) const ;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const ;

    QList<DeviceInfo> getDevices();
    void setDevices(QList<DeviceInfo> devices);


private:
    QList<DeviceInfo> m_devices;
};

#endif // DEVICELISTMODEL_H
