/********************************************************************************
** Form generated from reading UI file 'searchtoolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHTOOLBAR_H
#define UI_SEARCHTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchToolBar
{
public:
    QHBoxLayout *horizontalLayout;
    QComboBox *sortComboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;

    void setupUi(QWidget *SearchToolBar)
    {
        if (SearchToolBar->objectName().isEmpty())
            SearchToolBar->setObjectName(QString::fromUtf8("SearchToolBar"));
        SearchToolBar->resize(400, 50);
        horizontalLayout = new QHBoxLayout(SearchToolBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sortComboBox = new QComboBox(SearchToolBar);
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->setObjectName(QString::fromUtf8("sortComboBox"));

        horizontalLayout->addWidget(sortComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchLabel = new QLabel(SearchToolBar);
        searchLabel->setObjectName(QString::fromUtf8("searchLabel"));

        horizontalLayout->addWidget(searchLabel);

        searchLineEdit = new QLineEdit(SearchToolBar);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);


        retranslateUi(SearchToolBar);

        QMetaObject::connectSlotsByName(SearchToolBar);
    } // setupUi

    void retranslateUi(QWidget *SearchToolBar)
    {
        sortComboBox->setItemText(0, QCoreApplication::translate("SearchToolBar", "\346\234\200\350\277\221\344\275\277\347\224\250", nullptr));
        sortComboBox->setItemText(1, QCoreApplication::translate("SearchToolBar", "\345\220\215\347\247\260", nullptr));
        sortComboBox->setItemText(2, QCoreApplication::translate("SearchToolBar", "\345\244\247\345\260\217", nullptr));

        searchLabel->setText(QCoreApplication::translate("SearchToolBar", "\346\237\245\346\211\276\346\226\207\344\273\266\357\274\232", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("SearchToolBar", "\350\276\223\345\205\245\345\205\263\351\224\256\345\255\227\346\220\234\347\264\242", nullptr));
        (void)SearchToolBar;
    } // retranslateUi

};

namespace Ui {
    class SearchToolBar: public Ui_SearchToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHTOOLBAR_H
