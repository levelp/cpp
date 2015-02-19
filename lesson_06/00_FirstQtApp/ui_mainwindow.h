/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget* centralWidget;
  QPushButton* closeButton;
  QPushButton* pushButton;
  QLineEdit* lineEdit_1;
  QLineEdit* lineEdit_2;
  QPushButton* concatButton;
  QLineEdit* resEdit;
  QPushButton* pushButton_2;
  QPushButton* manualSignalSlotButton;
  QPushButton* enableButton;
  QMenuBar* menuBar;
  QToolBar* mainToolBar;
  QStatusBar* statusBar;

  void setupUi(QMainWindow* MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QStringLiteral("MainWindow"));

    MainWindow->resize(475, 315);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    closeButton = new QPushButton(centralWidget);
    closeButton->setObjectName(QStringLiteral("closeButton"));
    closeButton->setGeometry(QRect(80, 150, 181, 41));
    QFont font;
    font.setFamily(QStringLiteral("Verdana"));
    font.setPointSize(13);
    font.setBold(true);
    font.setItalic(true);
    font.setUnderline(true);
    font.setWeight(75);
    font.setStrikeOut(false);
    closeButton->setFont(font);
    pushButton = new QPushButton(centralWidget);
    pushButton->setObjectName(QStringLiteral("pushButton"));
    pushButton->setGeometry(QRect(150, 210, 151, 31));
    lineEdit_1 = new QLineEdit(centralWidget);
    lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
    lineEdit_1->setGeometry(QRect(70, 20, 113, 20));
    lineEdit_2 = new QLineEdit(centralWidget);
    lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
    lineEdit_2->setGeometry(QRect(210, 20, 113, 20));
    concatButton = new QPushButton(centralWidget);
    concatButton->setObjectName(QStringLiteral("concatButton"));
    concatButton->setEnabled(true);
    concatButton->setGeometry(QRect(150, 50, 91, 23));
    resEdit = new QLineEdit(centralWidget);
    resEdit->setObjectName(QStringLiteral("resEdit"));
    resEdit->setGeometry(QRect(110, 110, 211, 20));
    pushButton_2 = new QPushButton(centralWidget);
    pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
    pushButton_2->setGeometry(QRect(270, 50, 121, 23));
    manualSignalSlotButton = new QPushButton(centralWidget);
    manualSignalSlotButton->setObjectName(QStringLiteral("manualSignalSlotButton"));
    manualSignalSlotButton->setGeometry(QRect(300, 180, 101, 23));
    enableButton = new QPushButton(centralWidget);
    enableButton->setObjectName(QStringLiteral("enableButton"));
    enableButton->setGeometry(QRect(160, 80, 75, 23));
    MainWindow->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QStringLiteral("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 475, 21));
    MainWindow->setMenuBar(menuBar);
    mainToolBar = new QToolBar(MainWindow);
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    MainWindow->setStatusBar(statusBar);

    retranslateUi(MainWindow);
    QObject::connect(closeButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
    QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(on_concatButton_clicked()));

    QMetaObject::connectSlotsByName(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow* MainWindow) {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
    closeButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\276\320\272\320\275\320\276", 0));
    pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\264\320\270\320\260\320\273\320\276\320\263", 0));
    lineEdit_1->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", 0));
    concatButton->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214", 0));
    pushButton_2->setText(QApplication::translate("MainWindow", "\320\220\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\320\260\321\217....", 0));
    manualSignalSlotButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \321\204\320\276\321\200\320\274\321\203", 0));
    enableButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\265\321\202\320\270\321\202\321\214", 0));
  } // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
