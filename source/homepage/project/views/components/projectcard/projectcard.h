#ifndef PROJECTCARD_H
#define PROJECTCARD_H

#include <QWidget>
#include "global_h.h"

namespace Ui {
class ProjectCard;
}

class PROJECT_EXPORT ProjectCard : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectCard(QWidget *parent = nullptr);
    ~ProjectCard();

private:
    Ui::ProjectCard *ui;
};
#endif // PROJECTCARD_H

