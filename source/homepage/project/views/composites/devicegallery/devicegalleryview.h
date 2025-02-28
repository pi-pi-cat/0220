#ifndef DEVICEGALLERYVIEW_H
#define DEVICEGALLERYVIEW_H

#include <QWidget>
#include <QScrollArea>
#include "global_h.h"

class DeviceInfo;
class NewDeviceCard;
class DeviceCard;
class FlowLayout;

class PROJECT_EXPORT DeviceGalleryView : public QWidget
{
    Q_OBJECT
public:
    explicit DeviceGalleryView(QWidget *parent = nullptr);

    void addDeviceCard(DeviceCard *card);
    void addNewDeviceCard(NewDeviceCard *card);
    void onDeviceAdded(const DeviceInfo &device); //新增装置后视图更新
    void onDeviceRemoved(const DeviceInfo &device); //删除装置后视图更新

    void clear();

signals:
    void deviceCardClicked(const DeviceInfo &device);  // 点击信号
    void deviceCardDelete(const DeviceInfo &device);  // 点击信号

public:
    NewDeviceCard *m_addCard;
private:
    FlowLayout *m_flowLayout;
    QScrollArea *m_scrollArea;
    QWidget *m_area;
};

#endif // DEVICEGALLERYVIEW_H
