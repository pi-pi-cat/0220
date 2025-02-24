#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QWidget>
#include "global_h.h"

namespace Ui {
class LeftPanel;
}

class PROJECT_EXPORT LeftPanel : public QWidget
{
    Q_OBJECT

public:
    explicit LeftPanel(QWidget *parent = nullptr);
    ~LeftPanel();

private:
    Ui::LeftPanel *ui;
};

#endif // LEFTPANEL_H
