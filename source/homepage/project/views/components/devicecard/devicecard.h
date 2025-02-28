// devicecard.h
#ifndef DEVICECARD_H
#define DEVICECARD_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDateTime>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include "global_h.h"

class DeviceInfo;

class PROJECT_EXPORT DeviceCard : public QWidget {
    Q_OBJECT

public:
    DeviceCard(QWidget *parent = nullptr, int width = 450, int height = 350);
    DeviceCard(const DeviceInfo& info, QWidget *parent = nullptr, int width = 450, int height = 350);

    void setDeviceInfo(const DeviceInfo& info);
    DeviceInfo getDeviceInfo() const;
    QString deviceName() const;

signals:
    void copyClicked();
    void editClicked();
    void deleteClicked();
    void cardClicked();

protected:
    bool event(QEvent *event) override;

private:
    void setupUI();
    void setupConnections();
    void updateInfo(const DeviceInfo& deviceInfo);

    QWidget *m_containerWidget;
    QLabel *m_nameLabel;
    QPushButton *m_copyButton;
    QPushButton *m_editButton;
    QPushButton *m_deleteButton;
    QLabel *m_imageLabel;
    QLabel *m_creationTimeLabel;
    QLabel *m_modificationTimeLabel;
    QFrame *m_imageFrame;

    int m_width;
    int m_height;
};

class PROJECT_EXPORT NewDeviceCard : public QWidget
{
    Q_OBJECT

public:
    NewDeviceCard(QWidget *parent = nullptr, int width = 450, int height = 350);

signals:
    void createNewDevice();

protected:
    bool event(QEvent *event) override;

private:
    void setupUI();
    QWidget *m_containerWidget;
    QLabel *m_plusLabel;
    QPushButton *m_newButton;

    int m_width;
    int m_height;
};

#endif // DEVICECARD_H
