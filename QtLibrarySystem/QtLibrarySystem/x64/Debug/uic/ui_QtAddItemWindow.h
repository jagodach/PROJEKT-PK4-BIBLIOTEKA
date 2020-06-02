/********************************************************************************
** Form generated from reading UI file 'QtAddItemWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTADDITEMWINDOW_H
#define UI_QTADDITEMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include "QtAddWindowBase.h"

QT_BEGIN_NAMESPACE

class Ui_QtAddItemWindow
{
public:
    QGridLayout *gridLayout;
    QTextEdit *NameTextEdit;
    QDateEdit *CreationDateEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddButton;
    QPushButton *CancelButton;
    QSpacerItem *horizontalSpacer;
    QComboBox *ItemTypeComboBox;
    QTextEdit *LendPriceTextEdit;
    QComboBox *AuthorComboBox;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *ReleaseVersionTextEdit;
    QTextEdit *FormatTextEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(LibrarySystem::UI::QtAddWindowBase *QtAddItemWindow)
    {
        if (QtAddItemWindow->objectName().isEmpty())
            QtAddItemWindow->setObjectName(QString::fromUtf8("QtAddItemWindow"));
        QtAddItemWindow->resize(990, 412);
        gridLayout = new QGridLayout(QtAddItemWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        NameTextEdit = new QTextEdit(QtAddItemWindow);
        NameTextEdit->setObjectName(QString::fromUtf8("NameTextEdit"));
        NameTextEdit->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(NameTextEdit, 0, 5, 1, 1);

        CreationDateEdit = new QDateEdit(QtAddItemWindow);
        CreationDateEdit->setObjectName(QString::fromUtf8("CreationDateEdit"));

        gridLayout->addWidget(CreationDateEdit, 1, 6, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        AddButton = new QPushButton(QtAddItemWindow);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));

        horizontalLayout->addWidget(AddButton);

        CancelButton = new QPushButton(QtAddItemWindow);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        horizontalLayout->addWidget(CancelButton);


        gridLayout->addLayout(horizontalLayout, 6, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 7, 1, 1);

        ItemTypeComboBox = new QComboBox(QtAddItemWindow);
        ItemTypeComboBox->setObjectName(QString::fromUtf8("ItemTypeComboBox"));

        gridLayout->addWidget(ItemTypeComboBox, 0, 7, 1, 1);

        LendPriceTextEdit = new QTextEdit(QtAddItemWindow);
        LendPriceTextEdit->setObjectName(QString::fromUtf8("LendPriceTextEdit"));
        LendPriceTextEdit->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(LendPriceTextEdit, 1, 5, 1, 1);

        AuthorComboBox = new QComboBox(QtAddItemWindow);
        AuthorComboBox->setObjectName(QString::fromUtf8("AuthorComboBox"));

        gridLayout->addWidget(AuthorComboBox, 0, 6, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ReleaseVersionTextEdit = new QTextEdit(QtAddItemWindow);
        ReleaseVersionTextEdit->setObjectName(QString::fromUtf8("ReleaseVersionTextEdit"));
        ReleaseVersionTextEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(ReleaseVersionTextEdit);

        FormatTextEdit = new QTextEdit(QtAddItemWindow);
        FormatTextEdit->setObjectName(QString::fromUtf8("FormatTextEdit"));
        FormatTextEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(FormatTextEdit);


        gridLayout->addLayout(horizontalLayout_2, 2, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 6, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 7, 1, 1);


        retranslateUi(QtAddItemWindow);

        QMetaObject::connectSlotsByName(QtAddItemWindow);
    } // setupUi

    void retranslateUi(LibrarySystem::UI::QtAddWindowBase *QtAddItemWindow)
    {
        QtAddItemWindow->setWindowTitle(QCoreApplication::translate("QtAddItemWindow", "QtAddItemWindow", nullptr));
        NameTextEdit->setPlaceholderText(QCoreApplication::translate("QtAddItemWindow", "Name", nullptr));
        AddButton->setText(QCoreApplication::translate("QtAddItemWindow", "Add", nullptr));
        CancelButton->setText(QCoreApplication::translate("QtAddItemWindow", "Cancel", nullptr));
        LendPriceTextEdit->setPlaceholderText(QCoreApplication::translate("QtAddItemWindow", "Lend price", nullptr));
        ReleaseVersionTextEdit->setPlaceholderText(QCoreApplication::translate("QtAddItemWindow", "Release version", nullptr));
        FormatTextEdit->setPlaceholderText(QCoreApplication::translate("QtAddItemWindow", "Format", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtAddItemWindow: public Ui_QtAddItemWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTADDITEMWINDOW_H
