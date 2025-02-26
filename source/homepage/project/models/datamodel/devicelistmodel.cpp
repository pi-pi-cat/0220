#include "devicelistmodel.h"

DeviceListModel::DeviceListModel(QObject *parent) : QAbstractListModel(parent)
{

}

int DeviceListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_devices.size();
}

QVariant DeviceListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_devices.size())
        return QVariant();

    const DeviceInfo &item = m_devices.at(index.row());

    switch (role) {
    case Qt::DisplayRole:
        return item.name(); // 假设ProjectItem有name()方法

    case Qt::DecorationRole:
        return item.displayName(); // 假设ProjectItem有icon()方法

    // 可以添加其他角色...

    default:
        return QVariant();
    }
}

QList<DeviceInfo> DeviceListModel::getDevices()
{
    return m_devices;
}

void DeviceListModel::setDevices(QList<DeviceInfo> devices)
{
    m_devices = devices;
}

