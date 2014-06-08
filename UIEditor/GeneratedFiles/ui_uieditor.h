/********************************************************************************
** Form generated from reading UI file 'uieditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIEDITOR_H
#define UI_UIEDITOR_H

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

class Ui_UIEditorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UIEditorClass)
    {
        if (UIEditorClass->objectName().isEmpty())
            UIEditorClass->setObjectName(QStringLiteral("UIEditorClass"));
        UIEditorClass->resize(600, 400);
        menuBar = new QMenuBar(UIEditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        UIEditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UIEditorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        UIEditorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(UIEditorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        UIEditorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(UIEditorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        UIEditorClass->setStatusBar(statusBar);

        retranslateUi(UIEditorClass);

        QMetaObject::connectSlotsByName(UIEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *UIEditorClass)
    {
        UIEditorClass->setWindowTitle(QApplication::translate("UIEditorClass", "UIEditor", 0));
    } // retranslateUi

};

namespace Ui {
    class UIEditorClass: public Ui_UIEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIEDITOR_H
