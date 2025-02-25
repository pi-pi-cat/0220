#ifndef GALLERYVIEW_H
#define GALLERYVIEW_H

#include <QWidget>
#include "global_h.h"
#include "../toolbars/searchtoolbar.h"
#include "../../layouts/flowlayout.h"
#include "../../components/projectcard/projectcard.h"
#include "../../../models/internal/projectitem.h"

namespace Ui {
class GalleryView;
}

class PROJECT_EXPORT GalleryView : public QWidget
{
    Q_OBJECT

public:
    explicit GalleryView(QWidget *parent = nullptr);
    ~GalleryView();

    void addProjectCard(ProjectCard *card);
    void onProjectAdded(const ProjectItem &project); //新增项目后视图更新
    void onProjectRemoved(const ProjectItem &project); //删除项目后视图更新
    void sortCards(const QList<ProjectItem> &sortedProjects); //排序后视图更新

    void clear();

signals:
    void projectCardClicked(const ProjectItem& project);  // 点击信号
    void projectCardDelete(const ProjectItem& project);  // 点击信号

public:
    ProjectCard *m_addCard;
private:
    Ui::GalleryView *ui;
    FlowLayout *m_flowLayout;

};
#endif // GALLERYVIEW_H

