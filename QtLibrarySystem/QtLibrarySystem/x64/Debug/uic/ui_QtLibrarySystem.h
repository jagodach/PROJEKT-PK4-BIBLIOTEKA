/********************************************************************************
** Form generated from reading UI file 'QtLibrarySystem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTLIBRARYSYSTEM_H
#define UI_QTLIBRARYSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtLibrarySystemClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *MainMenuTabWidget;
    QWidget *LendsTab;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ReturnLendButton;
    QTableWidget *LendsTableWidget;
    QPushButton *DeleteLendButton;
    QWidget *ItemsTab;
    QGridLayout *gridLayout_3;
    QPushButton *AddItemButton;
    QPushButton *LendForUserButton;
    QTableWidget *ItemsTableWidget;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *LendButton;
    QPushButton *DeleteItemButton;
    QWidget *AuthorsTab;
    QGridLayout *gridLayout_4;
    QPushButton *AddAuthorButton;
    QTableWidget *AuthorsTableWidget;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *DeleteAuthorButton;
    QWidget *UsersTab;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *DeleteUsersButton;
    QPushButton *AddUserButton;
    QTableWidget *UsersTableWidget;

    void setupUi(QMainWindow *QtLibrarySystemClass)
    {
        if (QtLibrarySystemClass->objectName().isEmpty())
            QtLibrarySystemClass->setObjectName(QString::fromUtf8("QtLibrarySystemClass"));
        QtLibrarySystemClass->resize(886, 650);
        centralWidget = new QWidget(QtLibrarySystemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        MainMenuTabWidget = new QTabWidget(centralWidget);
        MainMenuTabWidget->setObjectName(QString::fromUtf8("MainMenuTabWidget"));
        LendsTab = new QWidget();
        LendsTab->setObjectName(QString::fromUtf8("LendsTab"));
        gridLayout = new QGridLayout(LendsTab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        ReturnLendButton = new QPushButton(LendsTab);
        ReturnLendButton->setObjectName(QString::fromUtf8("ReturnLendButton"));

        gridLayout->addWidget(ReturnLendButton, 2, 0, 1, 1);

        LendsTableWidget = new QTableWidget(LendsTab);
        LendsTableWidget->setObjectName(QString::fromUtf8("LendsTableWidget"));

        gridLayout->addWidget(LendsTableWidget, 0, 0, 1, 3);

        DeleteLendButton = new QPushButton(LendsTab);
        DeleteLendButton->setObjectName(QString::fromUtf8("DeleteLendButton"));

        gridLayout->addWidget(DeleteLendButton, 2, 1, 1, 1);

        MainMenuTabWidget->addTab(LendsTab, QString());
        ItemsTab = new QWidget();
        ItemsTab->setObjectName(QString::fromUtf8("ItemsTab"));
        gridLayout_3 = new QGridLayout(ItemsTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        AddItemButton = new QPushButton(ItemsTab);
        AddItemButton->setObjectName(QString::fromUtf8("AddItemButton"));

        gridLayout_3->addWidget(AddItemButton, 1, 2, 1, 1);

        LendForUserButton = new QPushButton(ItemsTab);
        LendForUserButton->setObjectName(QString::fromUtf8("LendForUserButton"));

        gridLayout_3->addWidget(LendForUserButton, 1, 1, 1, 1);

        ItemsTableWidget = new QTableWidget(ItemsTab);
        ItemsTableWidget->setObjectName(QString::fromUtf8("ItemsTableWidget"));

        gridLayout_3->addWidget(ItemsTableWidget, 0, 0, 1, 6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        LendButton = new QPushButton(ItemsTab);
        LendButton->setObjectName(QString::fromUtf8("LendButton"));

        gridLayout_3->addWidget(LendButton, 1, 0, 1, 1);

        DeleteItemButton = new QPushButton(ItemsTab);
        DeleteItemButton->setObjectName(QString::fromUtf8("DeleteItemButton"));

        gridLayout_3->addWidget(DeleteItemButton, 1, 3, 1, 1);

        MainMenuTabWidget->addTab(ItemsTab, QString());
        AuthorsTab = new QWidget();
        AuthorsTab->setObjectName(QString::fromUtf8("AuthorsTab"));
        gridLayout_4 = new QGridLayout(AuthorsTab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        AddAuthorButton = new QPushButton(AuthorsTab);
        AddAuthorButton->setObjectName(QString::fromUtf8("AddAuthorButton"));

        gridLayout_4->addWidget(AddAuthorButton, 3, 0, 1, 1);

        AuthorsTableWidget = new QTableWidget(AuthorsTab);
        AuthorsTableWidget->setObjectName(QString::fromUtf8("AuthorsTableWidget"));

        gridLayout_4->addWidget(AuthorsTableWidget, 0, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 3, 2, 1, 1);

        DeleteAuthorButton = new QPushButton(AuthorsTab);
        DeleteAuthorButton->setObjectName(QString::fromUtf8("DeleteAuthorButton"));

        gridLayout_4->addWidget(DeleteAuthorButton, 3, 1, 1, 1);

        MainMenuTabWidget->addTab(AuthorsTab, QString());
        UsersTab = new QWidget();
        UsersTab->setObjectName(QString::fromUtf8("UsersTab"));
        gridLayout_5 = new QGridLayout(UsersTab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        DeleteUsersButton = new QPushButton(UsersTab);
        DeleteUsersButton->setObjectName(QString::fromUtf8("DeleteUsersButton"));

        gridLayout_5->addWidget(DeleteUsersButton, 1, 1, 1, 1);

        AddUserButton = new QPushButton(UsersTab);
        AddUserButton->setObjectName(QString::fromUtf8("AddUserButton"));

        gridLayout_5->addWidget(AddUserButton, 1, 0, 1, 1);

        UsersTableWidget = new QTableWidget(UsersTab);
        UsersTableWidget->setObjectName(QString::fromUtf8("UsersTableWidget"));

        gridLayout_5->addWidget(UsersTableWidget, 0, 0, 1, 4);

        MainMenuTabWidget->addTab(UsersTab, QString());

        gridLayout_2->addWidget(MainMenuTabWidget, 0, 1, 1, 1);

        QtLibrarySystemClass->setCentralWidget(centralWidget);

        retranslateUi(QtLibrarySystemClass);

        MainMenuTabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(QtLibrarySystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtLibrarySystemClass)
    {
        QtLibrarySystemClass->setWindowTitle(QCoreApplication::translate("QtLibrarySystemClass", "QtLibrarySystem", nullptr));
        ReturnLendButton->setText(QCoreApplication::translate("QtLibrarySystemClass", "Return", nullptr));
        DeleteLendButton->setText(QCoreApplication::translate("QtLibrarySystemClass", "Delete", nullptr));
        MainMenuTabWidget->setTabText(MainMenuTabWidget->indexOf(LendsTab), QCoreApplication::translate("QtLibrarySystemClass", "Lends", nullptr));
        AddItemButton->setText(QCoreApplication::translate("QtLibrarySystemClass", "Add", nullptr));
        LendForUserButton->setText(QCoreApplication::translate("QtLibrarySystemClass", "Lend for user", nullptr));
        LendButton->setText(QCoreApplication::translate("QtLibrarySystemClass", "Lend", nullptr));
        DeleteItemButton->setText(QCoreApplication::translate("QtLibrarySystemClass", "Delete", nullptr));
        MainMenuTabWidget->setTabText(MainMenuTabWidget->indexOf(ItemsTab), QCoreApplication::translate("QtLibrarySystemClass", "Items", nullptr));
        AddAuthorButton->setText(QCoreApplication::translate("QtLibrarySystemClass", "Add", nullptr));
        DeleteAuthorButton->setText(QCoreApplication::translate("QtLibrarySystemClass", "Delete", nullptr));
        MainMenuTabWidget->setTabText(MainMenuTabWidget->indexOf(AuthorsTab), QCoreApplication::translate("QtLibrarySystemClass", "Authors", nullptr));
        DeleteUsersButton->setText(QCoreApplication::translate("QtLibrarySystemClass", "Delete", nullptr));
        AddUserButton->setText(QCoreApplication::translate("QtLibrarySystemClass", "Add", nullptr));
        MainMenuTabWidget->setTabText(MainMenuTabWidget->indexOf(UsersTab), QCoreApplication::translate("QtLibrarySystemClass", "Users", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtLibrarySystemClass: public Ui_QtLibrarySystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTLIBRARYSYSTEM_H
