/********************************************************************************
** Form generated from reading UI file 'QtAddUserWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTADDUSERWINDOW_H
#define UI_QTADDUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtAddUserWindow
{
public:
    QGridLayout *gridLayout;
    QTextEdit *PasswordTextEdit;
    QVBoxLayout *verticalLayout;
    QDateEdit *BirthdayDateEdit;
    QComboBox *UserTypeComboBox;
    QTextEdit *UsernameTextEdit;
    QTextEdit *SurnameTextEdit;
    QTextEdit *NameTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddButton;
    QPushButton *CancelButton;

    void setupUi(QWidget *QtAddUserWindow)
    {
        if (QtAddUserWindow->objectName().isEmpty())
            QtAddUserWindow->setObjectName(QString::fromUtf8("QtAddUserWindow"));
        QtAddUserWindow->resize(960, 300);
        gridLayout = new QGridLayout(QtAddUserWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PasswordTextEdit = new QTextEdit(QtAddUserWindow);
        PasswordTextEdit->setObjectName(QString::fromUtf8("PasswordTextEdit"));
        PasswordTextEdit->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(PasswordTextEdit, 3, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        BirthdayDateEdit = new QDateEdit(QtAddUserWindow);
        BirthdayDateEdit->setObjectName(QString::fromUtf8("BirthdayDateEdit"));

        verticalLayout->addWidget(BirthdayDateEdit);

        UserTypeComboBox = new QComboBox(QtAddUserWindow);
        UserTypeComboBox->setObjectName(QString::fromUtf8("UserTypeComboBox"));

        verticalLayout->addWidget(UserTypeComboBox);


        gridLayout->addLayout(verticalLayout, 0, 3, 1, 1);

        UsernameTextEdit = new QTextEdit(QtAddUserWindow);
        UsernameTextEdit->setObjectName(QString::fromUtf8("UsernameTextEdit"));
        UsernameTextEdit->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(UsernameTextEdit, 3, 0, 1, 1);

        SurnameTextEdit = new QTextEdit(QtAddUserWindow);
        SurnameTextEdit->setObjectName(QString::fromUtf8("SurnameTextEdit"));
        SurnameTextEdit->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(SurnameTextEdit, 0, 1, 1, 1);

        NameTextEdit = new QTextEdit(QtAddUserWindow);
        NameTextEdit->setObjectName(QString::fromUtf8("NameTextEdit"));
        NameTextEdit->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(NameTextEdit, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        AddButton = new QPushButton(QtAddUserWindow);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));

        horizontalLayout->addWidget(AddButton);

        CancelButton = new QPushButton(QtAddUserWindow);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        horizontalLayout->addWidget(CancelButton);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);


        retranslateUi(QtAddUserWindow);

        QMetaObject::connectSlotsByName(QtAddUserWindow);
    } // setupUi

    void retranslateUi(QWidget *QtAddUserWindow)
    {
        QtAddUserWindow->setWindowTitle(QCoreApplication::translate("QtAddUserWindow", "QtAddUserWindow", nullptr));
        PasswordTextEdit->setPlaceholderText(QCoreApplication::translate("QtAddUserWindow", "password", nullptr));
        UsernameTextEdit->setPlaceholderText(QCoreApplication::translate("QtAddUserWindow", "username", nullptr));
        SurnameTextEdit->setPlaceholderText(QCoreApplication::translate("QtAddUserWindow", "surname", nullptr));
        NameTextEdit->setPlaceholderText(QCoreApplication::translate("QtAddUserWindow", "name", nullptr));
        AddButton->setText(QCoreApplication::translate("QtAddUserWindow", "Add", nullptr));
        CancelButton->setText(QCoreApplication::translate("QtAddUserWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtAddUserWindow: public Ui_QtAddUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTADDUSERWINDOW_H
