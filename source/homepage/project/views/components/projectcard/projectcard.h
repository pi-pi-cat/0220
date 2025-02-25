#ifndef PROJECTCARD_H
#define PROJECTCARD_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include "global_h.h"


class ProjectItem;

namespace Ui {
class ProjectCard;
}

class PROJECT_EXPORT ProjectCard : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectCard(QWidget *parent = nullptr);
    explicit ProjectCard(const ProjectItem& item, QWidget *parent = nullptr);  // 新增构造函数
    ~ProjectCard();
    void setIsCreateCard(bool isCreate);  // 新增方法
    bool isCreateCard() const;  // 新增方法

signals:
    void cardClicked();
    void cardCreate();

protected:
    // 重写鼠标进入和离开事件
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::ProjectCard *ui;
    QLabel *m_plusIcon;
    bool m_isCreateCard;  // 判断自己是否新增卡片对象
    void setupPlusIcon();
    void updatePlusIconPosition();
};
#endif // PROJECTCARD_H

