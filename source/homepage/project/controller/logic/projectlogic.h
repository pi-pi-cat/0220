#ifndef PROJECTLOGIC_H
#define PROJECTLOGIC_H

#include <QObject>
#include "global_h.h"

class GalleryView;
class ProjectListModel;

class PROJECT_EXPORT ProjectLogic : public QObject
{
    Q_OBJECT
public:
    explicit ProjectLogic(QObject *parent = nullptr);
    void setProjectListModel(ProjectListModel *model);
    void setGalleryView(GalleryView *view);

public slots:
    void createNewProject();

private:
    // 对模型和视图的引用
    ProjectListModel* m_projectListModel;
    GalleryView* m_galleryView;

};
#endif // PROJECTLOGIC_H

