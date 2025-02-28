#ifndef PROJECTGALLERYVIEW_H
#define PROJECTGALLERYVIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "global_h.h"

class ProjectCard;
class ProjectItem;
class FlowLayout;

class PROJECT_EXPORT ProjectGalleryView : public QWidget
{
    Q_OBJECT
public:
    explicit ProjectGalleryView(QWidget *parent = nullptr);
    ~ProjectGalleryView();

    // ProjectCard management methods
    void addProjectCard(ProjectCard *card);
    void onProjectAdded(const ProjectItem &project);
    void onProjectRemoved(const ProjectItem &project);
    void sortCards(const QList<ProjectItem> &sortedProjects);
    void clear();

signals:
    // Signals emitted by this view
    void projectCardClicked(const ProjectItem &project);
    void projectCardDelete(const ProjectItem &project);
    void newProjectClicked();
    void openProjectClicked();
    void sortOrderChanged(int index);
    void searchTextChanged(const QString &text);

public:
    // Public member for the "add new project" card
    ProjectCard *m_addCard;

private:
    // UI components
    QWidget *createLeftPanel();
    QWidget *createToolbar();

    // Layout and containers
    QHBoxLayout *m_mainLayout;
    QWidget *m_leftPanel;
    QWidget *m_rightPanel;
    QVBoxLayout *m_rightLayout;
    QWidget *m_toolbar;
    QScrollArea *m_scrollArea;
    QWidget *m_scrollContent;
    FlowLayout *m_flowLayout;

    // Left panel controls
    QPushButton *m_newProjectButton;
    QPushButton *m_openProjectButton;

    // Toolbar controls
    QComboBox *m_sortComboBox;
    QLineEdit *m_searchLineEdit;
};

#endif // PROJECTGALLERYVIEW_H
