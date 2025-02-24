#ifndef PROJECTCARD_H
#define PROJECTCARD_H

#include <QWidget>
#include "global_h.h"

#include <QMouseEvent>

namespace Ui {
class ProjectCard;
}

class PROJECT_EXPORT ProjectCard : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectCard(QWidget *parent = nullptr);
    ~ProjectCard();

protected:
    // 重写鼠标进入和离开事件
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::ProjectCard *ui;
};
#endif // PROJECTCARD_H

