// main.cpp - Example usage
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QDebug>
#include "views/components/devicecard/devicecard.h"
#include "views/composites/devicegallery/devicegalleryview.h"
#include "models/internal/deviceinfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget mainWidget;
    DeviceGalleryView *gallery = new DeviceGalleryView(&mainWidget);
    QHBoxLayout *layout = new QHBoxLayout(&mainWidget);
    layout->addWidget(gallery); // 将gallery添加到布局

    // Create a regular device card

    // Set device info
    DeviceInfo info;
    info.setName("几何构型-1");
    info.setDisplayName("几何构型-1");
    info.setCreationTime(QDateTime::fromString("2025-02-19 12:00:00", "yyyy-MM-dd HH:mm:ss"));
    info.setModificationTime(QDateTime::fromString("2025-02-19 12:00:00", "yyyy-MM-dd HH:mm:ss"));
    info.setImagePath("C:/Users/yuexiaofeng/Downloads/卡片.png");

    DeviceCard *deviceCard = new DeviceCard(info);
    DeviceCard *deviceCard1 = new DeviceCard(info);
    gallery->addDeviceCard(deviceCard);
    gallery->addDeviceCard(deviceCard1);

    mainWidget.setWindowTitle("Device Cards");
    mainWidget.resize(950, 400);
    mainWidget.show();

    return a.exec();
}
