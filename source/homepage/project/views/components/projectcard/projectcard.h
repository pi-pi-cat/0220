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
    QString projectPath() const;
    QString projectName() const;
    QString uniqueId() const;

signals:
    void cardClicked();
    void cardCreate();
    void cardDelete();

protected:
    // 重写鼠标进入和离开事件
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_deleteButton_clicked();

private:
    Ui::ProjectCard *ui;
    QLabel *m_plusIcon;
    bool m_isCreateCard;  // 判断自己是否新增卡片对象
    void setupPlusIcon();
    void updatePlusIconPosition();
};
#endif // PROJECTCARD_H

