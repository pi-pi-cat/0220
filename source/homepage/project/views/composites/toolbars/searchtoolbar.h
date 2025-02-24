#ifndef SEARCHTOOLBAR_H
#define SEARCHTOOLBAR_H

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class SearchToolBar;
}

class SearchToolBar : public QWidget
{
    Q_OBJECT

public:
    explicit SearchToolBar(QWidget *parent = nullptr);
    ~SearchToolBar();

private:
    Ui::SearchToolBar *ui;
};

#endif // SEARCHTOOLBAR_H
