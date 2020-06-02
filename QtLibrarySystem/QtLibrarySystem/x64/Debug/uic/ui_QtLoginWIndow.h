/********************************************************************************
** Form generated from reading UI file 'QtLoginWIndow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTLOGINWINDOW_H
#define UI_QTLOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtLoginWIndow
{
public:
    QGridLayout *gridLayout;
    QPushButton *CancelButton;
    QTextEdit *PasswordTextEdit;
    QPushButton *LoginButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *UserNameTextEdit;

    void setupUi(QWidget *QtLoginWIndow)
    {
        if (QtLoginWIndow->objectName().isEmpty())
            QtLoginWIndow->setObjectName(QString::fromUtf8("QtLoginWIndow"));
        QtLoginWIndow->resize(958, 343);
        gridLayout = new QGridLayout(QtLoginWIndow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CancelButton = new QPushButton(QtLoginWIndow);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        gridLayout->addWidget(CancelButton, 3, 1, 1, 1);

        PasswordTextEdit = new QTextEdit(QtLoginWIndow);
        PasswordTextEdit->setObjectName(QString::fromUtf8("PasswordTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PasswordTextEdit->sizePolicy().hasHeightForWidth());
        PasswordTextEdit->setSizePolicy(sizePolicy);
        PasswordTextEdit->setMinimumSize(QSize(0, 20));
        PasswordTextEdit->setMaximumSize(QSize(16777215, 25));
        PasswordTextEdit->setBaseSize(QSize(0, 20));

        gridLayout->addWidget(PasswordTextEdit, 0, 1, 1, 1);

        LoginButton = new QPushButton(QtLoginWIndow);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));

        gridLayout->addWidget(LoginButton, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        UserNameTextEdit = new QTextEdit(QtLoginWIndow);
        UserNameTextEdit->setObjectName(QString::fromUtf8("UserNameTextEdit"));
        sizePolicy.setHeightForWidth(UserNameTextEdit->sizePolicy().hasHeightForWidth());
        UserNameTextEdit->setSizePolicy(sizePolicy);
        UserNameTextEdit->setMinimumSize(QSize(0, 20));
        UserNameTextEdit->setMaximumSize(QSize(16777215, 25));
        UserNameTextEdit->setBaseSize(QSize(0, 20));

        gridLayout->addWidget(UserNameTextEdit, 0, 0, 1, 1);


        retranslateUi(QtLoginWIndow);

        QMetaObject::connectSlotsByName(QtLoginWIndow);
    } // setupUi

    void retranslateUi(QWidget *QtLoginWIndow)
    {
        QtLoginWIndow->setWindowTitle(QCoreApplication::translate("QtLoginWIndow", "Login", nullptr));
        CancelButton->setText(QCoreApplication::translate("QtLoginWIndow", "Cancel", nullptr));
        PasswordTextEdit->setPlaceholderText(QCoreApplication::translate("QtLoginWIndow", "Password", nullptr));
        LoginButton->setText(QCoreApplication::translate("QtLoginWIndow", "Login", nullptr));
        UserNameTextEdit->setPlaceholderText(QCoreApplication::translate("QtLoginWIndow", "Username", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtLoginWIndow: public Ui_QtLoginWIndow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTLOGINWINDOW_H
