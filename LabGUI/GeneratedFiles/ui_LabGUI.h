/********************************************************************************
** Form generated from reading UI file 'LabGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABGUI_H
#define UI_LABGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LabGUIClass)
    {
        if (LabGUIClass->objectName().isEmpty())
            LabGUIClass->setObjectName(QString::fromUtf8("LabGUIClass"));
        LabGUIClass->resize(600, 400);
        menuBar = new QMenuBar(LabGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        LabGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LabGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LabGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(LabGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LabGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LabGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LabGUIClass->setStatusBar(statusBar);

        retranslateUi(LabGUIClass);

        QMetaObject::connectSlotsByName(LabGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *LabGUIClass)
    {
        LabGUIClass->setWindowTitle(QApplication::translate("LabGUIClass", "LabGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LabGUIClass: public Ui_LabGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABGUI_H
