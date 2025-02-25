#ifndef GALLERYVIEW_H
#define GALLERYVIEW_H

#include <QWidget>
#include "global_h.h"
#include "../toolbars/searchtoolbar.h"
#include "../../layouts/flowlayout.h"
#include "../../components/projectcard/projectcard.h"

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
    void onProjectAdded(const ProjectItem &project); //新增项目后
    void clear();

public:
    ProjectCard *m_addCard;
private:
    Ui::GalleryView *ui;
    FlowLayout *m_flowLayout;

};
#endif // GALLERYVIEW_H

