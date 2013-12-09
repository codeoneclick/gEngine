/********************************************************************************
** Form generated from reading UI file 'CMainWindowGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWINDOWGUI_H
#define UI_CMAINWINDOWGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWindowGUI
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *materials_list;
    QGroupBox *groupBox_2;
    QWidget *opengl_window;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainWindowGUI)
    {
        if (CMainWindowGUI->objectName().isEmpty())
            CMainWindowGUI->setObjectName(QStringLiteral("CMainWindowGUI"));
        CMainWindowGUI->resize(1024, 768);
        CMainWindowGUI->setMaximumSize(QSize(1024, 768));
        actionOpen = new QAction(CMainWindowGUI);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(CMainWindowGUI);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(CMainWindowGUI);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(CMainWindowGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(669, 10, 341, 691));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 80, 301, 32));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 120, 301, 32));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 160, 301, 32));
        materials_list = new QComboBox(groupBox);
        materials_list->setObjectName(QStringLiteral("materials_list"));
        materials_list->setGeometry(QRect(25, 40, 291, 26));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 9, 641, 691));
        opengl_window = new QWidget(groupBox_2);
        opengl_window->setObjectName(QStringLiteral("opengl_window"));
        opengl_window->setGeometry(QRect(9, 29, 621, 651));
        CMainWindowGUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CMainWindowGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        CMainWindowGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMainWindowGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CMainWindowGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CMainWindowGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CMainWindowGUI->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);

        retranslateUi(CMainWindowGUI);

        QMetaObject::connectSlotsByName(CMainWindowGUI);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindowGUI)
    {
        CMainWindowGUI->setWindowTitle(QApplication::translate("CMainWindowGUI", "CMainWindowGUI", 0));
        actionOpen->setText(QApplication::translate("CMainWindowGUI", "Open", 0));
        actionSave->setText(QApplication::translate("CMainWindowGUI", "Save", 0));
        actionExit->setText(QApplication::translate("CMainWindowGUI", "Exit", 0));
        groupBox->setTitle(QApplication::translate("CMainWindowGUI", "Settings", 0));
        pushButton->setText(QApplication::translate("CMainWindowGUI", "ShaderCompile", 0));
        pushButton_2->setText(QApplication::translate("CMainWindowGUI", "MaterialSettings", 0));
        pushButton_3->setText(QApplication::translate("CMainWindowGUI", "MaterialExport", 0));
        groupBox_2->setTitle(QApplication::translate("CMainWindowGUI", "3D", 0));
        menuFile->setTitle(QApplication::translate("CMainWindowGUI", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class CMainWindowGUI: public Ui_CMainWindowGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWINDOWGUI_H
