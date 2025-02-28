#ifndef PROJECTCARD_H
#define PROJECTCARD_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QPushButton>
#include "global_h.h"

class ProjectItem;

class PROJECT_EXPORT ProjectCard : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectCard(QWidget *parent = nullptr);
    explicit ProjectCard(const ProjectItem& item, QWidget *parent = nullptr);
    ~ProjectCard();

    void setIsCreateCard(bool isCreate);
    bool isCreateCard() const;
    QString projectPath() const;
    QString projectName() const;
    QString uniqueId() const;

signals:
    void cardClicked();
    void cardCreate();
    void cardDelete();

protected:
    bool event(QEvent *event) override;

private slots:
    void on_deleteButton_clicked();

private:
    void setupUi();
    void loadStyleSheet();
    void setupPlusIcon();
    void updatePlusIconPosition();

    // UI components
    QLabel *m_projectNameLabel;
    QLabel *m_projectPathLabel;
    QLabel *m_lastModifiedLabel;
    QPushButton *m_editButton;
    QPushButton *m_deleteButton;
    QWidget *m_mainWidget;
    QWidget *m_imageContainer;
    QLabel *m_imageLabels[4];

    // State
    QLabel *m_plusIcon;
    bool m_isCreateCard;
};
#endif // PROJECTCARD_H
