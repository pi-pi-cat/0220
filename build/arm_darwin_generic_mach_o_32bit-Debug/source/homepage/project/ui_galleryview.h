/********************************************************************************
** Form generated from reading UI file 'galleryview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GALLERYVIEW_H
#define UI_GALLERYVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <searchtoolbar.h>

QT_BEGIN_NAMESPACE

class Ui_GalleryView
{
public:
    QVBoxLayout *verticalLayout;
    SearchToolBar *searchToolbar;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *GalleryView)
    {
        if (GalleryView->objectName().isEmpty())
            GalleryView->setObjectName(QString::fromUtf8("GalleryView"));
        GalleryView->resize(400, 300);
        verticalLayout = new QVBoxLayout(GalleryView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        searchToolbar = new SearchToolBar(GalleryView);
        searchToolbar->setObjectName(QString::fromUtf8("searchToolbar"));

        verticalLayout->addWidget(searchToolbar);

        scrollArea = new QScrollArea(GalleryView);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 374, 254));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(GalleryView);

        QMetaObject::connectSlotsByName(GalleryView);
    } // setupUi

    void retranslateUi(QWidget *GalleryView)
    {
        (void)GalleryView;
    } // retranslateUi

};

namespace Ui {
    class GalleryView: public Ui_GalleryView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GALLERYVIEW_H
