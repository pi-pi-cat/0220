#ifndef PROJECTLOGIC_H
#define PROJECTLOGIC_H

#include <QObject>
#include <QDebug>
#include "../../models/datamodel/projectlistmodel.h"
#include "global_h.h"

class GalleryView;
class ProjectItem;

class PROJECT_EXPORT ProjectLogic : public QObject
{
    Q_OBJECT
public:
    explicit ProjectLogic(QObject *parent = nullptr);
    void setProjectListModel(ProjectListModel *model);
    void setGalleryView(GalleryView *view);
    void loadInitialProjects();

public slots:
    void createNewProject();
    void openProject(const ProjectItem& project);  // 接收打开项目信号
    void deleteProject(const ProjectItem& project);  // 接收删除项目信号
    void sortProjects(ProjectListModel::SortRole sortRole);

signals:
    void projectOpened(const ProjectItem& project);  // 发送给主窗口信号

private:
    // 对模型和视图的引用
    ProjectListModel* m_projectListModel;
    GalleryView* m_galleryView;


};
#endif // PROJECTLOGIC_H

