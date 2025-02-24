/********************************************************************************
** Form generated from reading UI file 'leftpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTPANEL_H
#define UI_LEFTPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeftPanel
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *newProjectButton;
    QPushButton *openProjectButton;

    void setupUi(QWidget *LeftPanel)
    {
        if (LeftPanel->objectName().isEmpty())
            LeftPanel->setObjectName(QString::fromUtf8("LeftPanel"));
        LeftPanel->resize(151, 300);
        widget = new QWidget(LeftPanel);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 30, 85, 66));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        newProjectButton = new QPushButton(widget);
        newProjectButton->setObjectName(QString::fromUtf8("newProjectButton"));

        verticalLayout->addWidget(newProjectButton);

        openProjectButton = new QPushButton(widget);
        openProjectButton->setObjectName(QString::fromUtf8("openProjectButton"));

        verticalLayout->addWidget(openProjectButton);


        retranslateUi(LeftPanel);

        QMetaObject::connectSlotsByName(LeftPanel);
    } // setupUi

    void retranslateUi(QWidget *LeftPanel)
    {
        LeftPanel->setWindowTitle(QCoreApplication::translate("LeftPanel", "Form", nullptr));
        newProjectButton->setText(QCoreApplication::translate("LeftPanel", "\346\226\260\345\273\272\345\267\245\347\250\213", nullptr));
        openProjectButton->setText(QCoreApplication::translate("LeftPanel", "\346\211\223\345\274\200\345\267\245\347\250\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LeftPanel: public Ui_LeftPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTPANEL_H
