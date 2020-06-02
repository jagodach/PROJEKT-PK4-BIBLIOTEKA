/********************************************************************************
** Form generated from reading UI file 'QtAddAuthorWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTADDAUTHORWINDOW_H
#define UI_QTADDAUTHORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QtAddAuthorWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextEdit *NameTextEdit;
    QTextEdit *SurnameTextEdit;
    QVBoxLayout *verticalLayout_2;
    QDateEdit *BirthdayDateEdit;
    QComboBox *AuthorTypeComboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddButton;
    QPushButton *CancelButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *QtAddAuthorWindow)
    {
        if (QtAddAuthorWindow->objectName().isEmpty())
            QtAddAuthorWindow->setObjectName(QString::fromUtf8("QtAddAuthorWindow"));
        QtAddAuthorWindow->resize(973, 245);
        gridLayout = new QGridLayout(QtAddAuthorWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        NameTextEdit = new QTextEdit(QtAddAuthorWindow);
        NameTextEdit->setObjectName(QString::fromUtf8("NameTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NameTextEdit->sizePolicy().hasHeightForWidth());
        NameTextEdit->setSizePolicy(sizePolicy);
        NameTextEdit->setMinimumSize(QSize(0, 15));
        NameTextEdit->setMaximumSize(QSize(16777215, 25));
        NameTextEdit->setBaseSize(QSize(0, 15));

        horizontalLayout->addWidget(NameTextEdit);

        SurnameTextEdit = new QTextEdit(QtAddAuthorWindow);
        SurnameTextEdit->setObjectName(QString::fromUtf8("SurnameTextEdit"));
        sizePolicy.setHeightForWidth(SurnameTextEdit->sizePolicy().hasHeightForWidth());
        SurnameTextEdit->setSizePolicy(sizePolicy);
        SurnameTextEdit->setMinimumSize(QSize(0, 15));
        SurnameTextEdit->setMaximumSize(QSize(16777215, 25));
        SurnameTextEdit->setBaseSize(QSize(0, 15));
        SurnameTextEdit->setTabStopWidth(80);

        horizontalLayout->addWidget(SurnameTextEdit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        BirthdayDateEdit = new QDateEdit(QtAddAuthorWindow);
        BirthdayDateEdit->setObjectName(QString::fromUtf8("BirthdayDateEdit"));

        verticalLayout_2->addWidget(BirthdayDateEdit);

        AuthorTypeComboBox = new QComboBox(QtAddAuthorWindow);
        AuthorTypeComboBox->setObjectName(QString::fromUtf8("AuthorTypeComboBox"));

        verticalLayout_2->addWidget(AuthorTypeComboBox);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        AddButton = new QPushButton(QtAddAuthorWindow);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));

        horizontalLayout_2->addWidget(AddButton);

        CancelButton = new QPushButton(QtAddAuthorWindow);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        horizontalLayout_2->addWidget(CancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(QtAddAuthorWindow);

        QMetaObject::connectSlotsByName(QtAddAuthorWindow);
    } // setupUi

    void retranslateUi(QDialog *QtAddAuthorWindow)
    {
        QtAddAuthorWindow->setWindowTitle(QCoreApplication::translate("QtAddAuthorWindow", "QtAddAuthorWindow", nullptr));
        NameTextEdit->setPlaceholderText(QCoreApplication::translate("QtAddAuthorWindow", "name", nullptr));
        SurnameTextEdit->setPlaceholderText(QCoreApplication::translate("QtAddAuthorWindow", "surname", nullptr));
        AddButton->setText(QCoreApplication::translate("QtAddAuthorWindow", "Add", nullptr));
        CancelButton->setText(QCoreApplication::translate("QtAddAuthorWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtAddAuthorWindow: public Ui_QtAddAuthorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTADDAUTHORWINDOW_H
