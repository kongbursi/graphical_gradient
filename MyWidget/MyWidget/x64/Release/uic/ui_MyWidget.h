/********************************************************************************
** Form generated from reading UI file 'MyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidgetClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyWidgetClass)
    {
        if (MyWidgetClass->objectName().isEmpty())
            MyWidgetClass->setObjectName(QStringLiteral("MyWidgetClass"));
        MyWidgetClass->resize(600, 400);
        menuBar = new QMenuBar(MyWidgetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyWidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyWidgetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyWidgetClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyWidgetClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyWidgetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyWidgetClass->setStatusBar(statusBar);

        retranslateUi(MyWidgetClass);

        QMetaObject::connectSlotsByName(MyWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyWidgetClass)
    {
        MyWidgetClass->setWindowTitle(QApplication::translate("MyWidgetClass", "MyWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyWidgetClass: public Ui_MyWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
