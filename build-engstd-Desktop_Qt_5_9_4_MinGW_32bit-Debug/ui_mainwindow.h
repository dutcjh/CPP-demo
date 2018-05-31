/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionda;
    QAction *actionsave;
    QAction *actionsava_as;
    QAction *actionclose;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *intxt;
    QLineEdit *outtxt;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *file;
    QMenu *edit;
    QMenu *view;
    QMenu *help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(759, 470);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        MainWindow->setFont(font);
        actionda = new QAction(MainWindow);
        actionda->setObjectName(QStringLiteral("actionda"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionsava_as = new QAction(MainWindow);
        actionsava_as->setObjectName(QStringLiteral("actionsava_as"));
        actionclose = new QAction(MainWindow);
        actionclose->setObjectName(QStringLiteral("actionclose"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 170, 93, 28));
        intxt = new QLineEdit(centralWidget);
        intxt->setObjectName(QStringLiteral("intxt"));
        intxt->setGeometry(QRect(130, 80, 451, 41));
        QFont font1;
        font1.setPointSize(12);
        intxt->setFont(font1);
        outtxt = new QLineEdit(centralWidget);
        outtxt->setObjectName(QStringLiteral("outtxt"));
        outtxt->setGeometry(QRect(130, 260, 451, 41));
        outtxt->setFont(font1);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 170, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 151, 31));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 170, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 759, 21));
        file = new QMenu(menuBar);
        file->setObjectName(QStringLiteral("file"));
        edit = new QMenu(menuBar);
        edit->setObjectName(QStringLiteral("edit"));
        view = new QMenu(menuBar);
        view->setObjectName(QStringLiteral("view"));
        help = new QMenu(menuBar);
        help->setObjectName(QStringLiteral("help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(file->menuAction());
        menuBar->addAction(edit->menuAction());
        menuBar->addAction(view->menuAction());
        menuBar->addAction(help->menuAction());
        file->addSeparator();
        file->addAction(actionda);
        file->addAction(actionsave);
        file->addAction(actionsava_as);
        file->addAction(actionclose);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), intxt, SLOT(clear()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), outtxt, SLOT(clear()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionda->setText(QApplication::translate("MainWindow", "open", Q_NULLPTR));
        actionsave->setText(QApplication::translate("MainWindow", "save", Q_NULLPTR));
        actionsava_as->setText(QApplication::translate("MainWindow", "sava as", Q_NULLPTR));
        actionclose->setText(QApplication::translate("MainWindow", "close", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\240\207\351\242\2301", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        edit->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", Q_NULLPTR));
        view->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213", Q_NULLPTR));
        help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
