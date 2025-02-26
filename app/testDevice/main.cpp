// main.cpp - Example usage
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QDebug>
#include "views/components/devicecard/devicecard.h"
#include "models/internal/deviceinfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget mainWidget;
    QHBoxLayout *layout = new QHBoxLayout(&mainWidget);

    // Create a regular device card

    // Set device info
    DeviceInfo info;
    info.setName("几何构型-1");
    info.setDisplayName("几何构型-1");
    info.setCreationTime(QDateTime::fromString("2025-02-19 12:00:00", "yyyy-MM-dd HH:mm:ss"));
    info.setModificationTime(QDateTime::fromString("2025-02-19 12:00:00", "yyyy-MM-dd HH:mm:ss"));
    info.setImagePath("C:/Users/yuexiaofeng/Downloads/卡片.png");

    DeviceCard *deviceCard = new DeviceCard(info);

    // Create a new device card
    NewDeviceCard *newCard = new NewDeviceCard();

    // Add cards to layout
    layout->addWidget(deviceCard);
    layout->addWidget(newCard);

    // Connect signals
    QObject::connect(deviceCard, &DeviceCard::copyClicked, [&]() {
        qDebug() << "Copy clicked";
    });

    QObject::connect(deviceCard, &DeviceCard::editClicked, [&]() {
        qDebug() << "Edit clicked";
    });

    QObject::connect(deviceCard, &DeviceCard::deleteClicked, [&]() {
        qDebug() << "Delete clicked";
    });


    mainWidget.setWindowTitle("Device Cards");
    mainWidget.resize(950, 400);
    mainWidget.show();

    return a.exec();
}
