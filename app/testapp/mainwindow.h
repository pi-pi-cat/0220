#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ProjectItem;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void onProjectOpened(const ProjectItem& project);  // 新增槽函数


};
#endif // MAINWINDOW_H
