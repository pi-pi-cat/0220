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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectCard
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *imageContainer;
    QGridLayout *gridLayout;
    QLabel *imageLabel1;
    QLabel *imageLabel2;
    QLabel *imageLabel3;
    QLabel *imageLabel4;
    QHBoxLayout *titleLayout;
    QLabel *projectNameLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QLabel *projectPathLabel;
    QLabel *lastModifiedLabel;

    void setupUi(QWidget *ProjectCard)
    {
        if (ProjectCard->objectName().isEmpty())
            ProjectCard->setObjectName(QString::fromUtf8("ProjectCard"));
        ProjectCard->resize(280, 240);
        ProjectCard->setMinimumSize(QSize(280, 240));
        verticalLayout = new QVBoxLayout(ProjectCard);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        imageContainer = new QWidget(ProjectCard);
        imageContainer->setObjectName(QString::fromUtf8("imageContainer"));
        imageContainer->setMinimumSize(QSize(0, 120));
        gridLayout = new QGridLayout(imageContainer);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        imageLabel1 = new QLabel(imageContainer);
        imageLabel1->setObjectName(QString::fromUtf8("imageLabel1"));
        imageLabel1->setMinimumSize(QSize(120, 58));
        imageLabel1->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0;\n"
"border-radius: 4px;"));

        gridLayout->addWidget(imageLabel1, 0, 0, 1, 1);

        imageLabel2 = new QLabel(imageContainer);
        imageLabel2->setObjectName(QString::fromUtf8("imageLabel2"));
        imageLabel2->setMinimumSize(QSize(120, 58));
        imageLabel2->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0;\n"
"border-radius: 4px;"));

        gridLayout->addWidget(imageLabel2, 0, 1, 1, 1);

        imageLabel3 = new QLabel(imageContainer);
        imageLabel3->setObjectName(QString::fromUtf8("imageLabel3"));
        imageLabel3->setMinimumSize(QSize(120, 58));
        imageLabel3->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0;\n"
"border-radius: 4px;"));

        gridLayout->addWidget(imageLabel3, 1, 0, 1, 1);

        imageLabel4 = new QLabel(imageContainer);
        imageLabel4->setObjectName(QString::fromUtf8("imageLabel4"));
        imageLabel4->setMinimumSize(QSize(120, 58));
        imageLabel4->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0;\n"
"border-radius: 4px;"));

        gridLayout->addWidget(imageLabel4, 1, 1, 1, 1);


        verticalLayout->addWidget(imageContainer);

        titleLayout = new QHBoxLayout();
        titleLayout->setObjectName(QString::fromUtf8("titleLayout"));
        projectNameLabel = new QLabel(ProjectCard);
        projectNameLabel->setObjectName(QString::fromUtf8("projectNameLabel"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        projectNameLabel->setFont(font);

        titleLayout->addWidget(projectNameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        titleLayout->addItem(horizontalSpacer);

        editButton = new QPushButton(ProjectCard);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setMinimumSize(QSize(24, 24));
        editButton->setMaximumSize(QSize(24, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/edit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon);
        editButton->setFlat(true);

        titleLayout->addWidget(editButton);

        deleteButton = new QPushButton(ProjectCard);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setMinimumSize(QSize(24, 24));
        deleteButton->setMaximumSize(QSize(24, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/delete.svg"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setFlat(true);

        titleLayout->addWidget(deleteButton);


        verticalLayout->addLayout(titleLayout);

        projectPathLabel = new QLabel(ProjectCard);
        projectPathLabel->setObjectName(QString::fromUtf8("projectPathLabel"));
        QFont font1;
        font1.setPointSize(9);
        projectPathLabel->setFont(font1);
        projectPathLabel->setStyleSheet(QString::fromUtf8("color: #666666;"));
        projectPathLabel->setWordWrap(true);

        verticalLayout->addWidget(projectPathLabel);

        lastModifiedLabel = new QLabel(ProjectCard);
        lastModifiedLabel->setObjectName(QString::fromUtf8("lastModifiedLabel"));
        lastModifiedLabel->setFont(font1);
        lastModifiedLabel->setStyleSheet(QString::fromUtf8("color: #666666;"));

        verticalLayout->addWidget(lastModifiedLabel);


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
