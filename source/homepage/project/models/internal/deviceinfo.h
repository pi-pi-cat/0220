#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QString>
#include <QDateTime>

class DeviceInfo
{
public:
    DeviceInfo() = default;

    DeviceInfo(const QString& name, const QString& displayName,
               const QDateTime& creation, const QDateTime& modification,
               const QString& description, const QString& status)
        : m_name(name), m_displayName(displayName),
        m_creationTime(creation), m_modificationTime(modification),
        m_description(description), m_status(status), m_isNewCard(false)
    {}

    // Getters
    QString name() const { return m_name; }
    QString displayName() const { return m_displayName; }
    QDateTime creationTime() const { return m_creationTime; }
    QDateTime modificationTime() const { return m_modificationTime; }
    QString description() const { return m_description; }
    QString status() const { return m_status; }
    QString imagePath() const {return m_imagePath; }
    bool isNewCard() const { return m_isNewCard; }

    // Setters
    void setName(const QString& name) { m_name = name; }
    void setDisplayName(const QString& displayName) { m_displayName = displayName; }
    void setCreationTime(const QDateTime& time) { m_creationTime = time; }
    void setModificationTime(const QDateTime& time) { m_modificationTime = time; }
    void setDescription(const QString& description) { m_description = description; }
    void setStatus(const QString& status) { m_status = status; }
    void setImagePath(const QString& imagePath){ m_imagePath = imagePath; }
    void setIsNewCard(bool isNew) { m_isNewCard = isNew; }

private:
    QString m_name;
    QString m_displayName;
    QDateTime m_creationTime;
    QDateTime m_modificationTime;
    QString m_description;
    QString m_status;
    QString m_imagePath;
    bool m_isNewCard;
};

#endif // DEVICEINFO_H
