#ifndef PROJECTMEDIATOR_H
#define PROJECTMEDIATOR_H

#include <QObject>
#include <QDebug>
#include "global_h.h"

class ProjectLogic;
class GalleryView;
class ProjectListModel;
class ProjectCard;

class PROJECT_EXPORT ProjectMediator : public QObject
{
    Q_OBJECT
public:
    explicit ProjectMediator(QObject *parent = nullptr);

    // 初始化方法，用于设置连接
    void initialize(GalleryView *galleryView, ProjectLogic *projectLogic, ProjectListModel *projectListModel);

private:
    void connectSignals();

    GalleryView *m_galleryView;
    ProjectLogic *m_projectLogic;
    ProjectListModel *m_projectListModel;

};

#endif // PROJECTMEDIATOR_H
