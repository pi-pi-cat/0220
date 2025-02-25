/********************************************************************************
** Form generated from reading UI file 'projectcard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTCARD_H
#define UI_PROJECTCARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectCard
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout;
    QWidget *imageContainer;
    QGridLayout *gridLayout;
    QLabel *imageLabel1;
    QLabel *imageLabel2;
    QLabel *imageLabel3;
    QLabel *imageLabel4;
    QHBoxLayout *horizontalLayout;
    QLabel *projectNameLabel;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QLabel *projectPathLabel;
    QLabel *lastModifiedLabel;

    void setupUi(QWidget *ProjectCard)
    {
        if (ProjectCard->objectName().isEmpty())
            ProjectCard->setObjectName(QString::fromUtf8("ProjectCard"));
        ProjectCard->resize(500, 382);
        ProjectCard->setMinimumSize(QSize(500, 382));
        ProjectCard->setMaximumSize(QSize(500, 382));
        verticalLayout_2 = new QVBoxLayout(ProjectCard);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        mainWidget = new QWidget(ProjectCard);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->setMinimumSize(QSize(474, 358));
        mainWidget->setMaximumSize(QSize(474, 358));
        mainWidget->setStyleSheet(QString::fromUtf8("QWidget#mainWidget {border: 1px solid; background-color: #f7faff; border-radius: 10px;}"));
        verticalLayout = new QVBoxLayout(mainWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        imageContainer = new QWidget(mainWidget);
        imageContainer->setObjectName(QString::fromUtf8("imageContainer"));
        imageContainer->setMinimumSize(QSize(450, 250));
        imageContainer->setMaximumSize(QSize(450, 250));
        gridLayout = new QGridLayout(imageContainer);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        imageLabel1 = new QLabel(imageContainer);
        imageLabel1->setObjectName(QString::fromUtf8("imageLabel1"));
        imageLabel1->setMinimumSize(QSize(200, 100));
        imageLabel1->setMaximumSize(QSize(200, 100));
        imageLabel1->setStyleSheet(QString::fromUtf8("background-color: #a0f0f0;\n"
"border-radius: 10px;\n"
""));

        gridLayout->addWidget(imageLabel1, 0, 0, 1, 1);

        imageLabel2 = new QLabel(imageContainer);
        imageLabel2->setObjectName(QString::fromUtf8("imageLabel2"));
        imageLabel2->setMinimumSize(QSize(200, 100));
        imageLabel2->setMaximumSize(QSize(200, 100));
        imageLabel2->setStyleSheet(QString::fromUtf8("background-color: #a0f0f0;\n"
"border-radius: 10px;"));

        gridLayout->addWidget(imageLabel2, 0, 1, 1, 1);

        imageLabel3 = new QLabel(imageContainer);
        imageLabel3->setObjectName(QString::fromUtf8("imageLabel3"));
        imageLabel3->setMinimumSize(QSize(200, 100));
        imageLabel3->setMaximumSize(QSize(200, 100));
        imageLabel3->setStyleSheet(QString::fromUtf8("background-color: #a0f0f0;\n"
"border-radius: 10px;"));

        gridLayout->addWidget(imageLabel3, 1, 0, 1, 1);

        imageLabel4 = new QLabel(imageContainer);
        imageLabel4->setObjectName(QString::fromUtf8("imageLabel4"));
        imageLabel4->setMinimumSize(QSize(200, 100));
        imageLabel4->setMaximumSize(QSize(200, 100));
        imageLabel4->setStyleSheet(QString::fromUtf8("background-color: #a0f0f0;\n"
"border-radius: 10px;"));

        gridLayout->addWidget(imageLabel4, 1, 1, 1, 1);


        verticalLayout->addWidget(imageContainer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        projectNameLabel = new QLabel(mainWidget);
        projectNameLabel->setObjectName(QString::fromUtf8("projectNameLabel"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        projectNameLabel->setFont(font);
        projectNameLabel->setStyleSheet(QString::fromUtf8(""));
        projectNameLabel->setIndent(10);

        horizontalLayout->addWidget(projectNameLabel);

        editButton = new QPushButton(mainWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setMinimumSize(QSize(24, 24));
        editButton->setMaximumSize(QSize(24, 24));
        editButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/edit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon);
        editButton->setFlat(true);

        horizontalLayout->addWidget(editButton);

        deleteButton = new QPushButton(mainWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setMinimumSize(QSize(24, 24));
        deleteButton->setMaximumSize(QSize(24, 24));
        deleteButton->setStyleSheet(QString::fromUtf8("border: none; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/delete.svg"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setFlat(true);

        horizontalLayout->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout);

        projectPathLabel = new QLabel(mainWidget);
        projectPathLabel->setObjectName(QString::fromUtf8("projectPathLabel"));
        QFont font1;
        font1.setPointSize(9);
        projectPathLabel->setFont(font1);
        projectPathLabel->setStyleSheet(QString::fromUtf8("color: #666666;"));
        projectPathLabel->setWordWrap(true);
        projectPathLabel->setIndent(10);

        verticalLayout->addWidget(projectPathLabel);

        lastModifiedLabel = new QLabel(mainWidget);
        lastModifiedLabel->setObjectName(QString::fromUtf8("lastModifiedLabel"));
        lastModifiedLabel->setFont(font1);
        lastModifiedLabel->setStyleSheet(QString::fromUtf8("color: #666666;"));
        lastModifiedLabel->setIndent(10);

        verticalLayout->addWidget(lastModifiedLabel);


        verticalLayout_2->addWidget(mainWidget);


        retranslateUi(ProjectCard);

        QMetaObject::connectSlotsByName(ProjectCard);
    } // setupUi

    void retranslateUi(QWidget *ProjectCard)
    {
        projectNameLabel->setText(QCoreApplication::translate("ProjectCard", "\351\241\271\347\233\256\345\220\215\347\247\260", nullptr));
#if QT_CONFIG(tooltip)
        editButton->setToolTip(QCoreApplication::translate("ProjectCard", "\347\274\226\350\276\221", nullptr));
#endif // QT_CONFIG(tooltip)
        editButton->setText(QCoreApplication::translate("ProjectCard", "E", nullptr));
#if QT_CONFIG(tooltip)
        deleteButton->setToolTip(QCoreApplication::translate("ProjectCard", "\345\210\240\351\231\244", nullptr));
#endif // QT_CONFIG(tooltip)
        deleteButton->setText(QCoreApplication::translate("ProjectCard", "D", nullptr));
        projectPathLabel->setText(QCoreApplication::translate("ProjectCard", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        lastModifiedLabel->setText(QCoreApplication::translate("ProjectCard", "\344\277\256\346\224\271\346\227\266\351\227\264\357\274\232", nullptr));
        (void)ProjectCard;
    } // retranslateUi

};

namespace Ui {
    class ProjectCard: public Ui_ProjectCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTCARD_H
