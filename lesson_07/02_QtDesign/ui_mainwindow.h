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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget* centralWidget;
  QToolButton* toolButton;
  QLabel* label;
  QLabel* label_2;
  QPushButton* pushButton;
  QPushButton* pushButton_2;
  QMenuBar* menuBar;
  QToolBar* mainToolBar;
  QStatusBar* statusBar;

  void setupUi(QMainWindow* MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QStringLiteral("MainWindow"));

    MainWindow->resize(424, 323);
    QFont font;
    font.setFamily(QStringLiteral("Narkisim"));
    font.setPointSize(16);
    font.setBold(false);
    font.setItalic(false);
    font.setWeight(50);
    MainWindow->setFont(font);
    MainWindow->setCursor(QCursor(Qt::ArrowCursor));
    MainWindow->setStyleSheet(QLatin1String("* { color: rgb(85, 0, 0) }\n"
                                            ".QLabel{ color: rgb(0, 255, 127) }\n"
                                            ".QPushButton { color: red }\n"
                                            "* { \n"
                                            "	font: 16pt \"Narkisim\";\n"
                                            "}"));
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    toolButton = new QToolButton(centralWidget);
    toolButton->setObjectName(QStringLiteral("toolButton"));
    toolButton->setGeometry(QRect(40, 50, 161, 151));
    QIcon icon;
    icon.addFile(QStringLiteral(":/img/img/bigRedButton.png"), QSize(), QIcon::Normal, QIcon::Off);
    toolButton->setIcon(icon);
    toolButton->setIconSize(QSize(346, 328));
    label = new QLabel(centralWidget);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(QRect(250, 40, 101, 16));
    label_2 = new QLabel(centralWidget);
    label_2->setObjectName(QStringLiteral("label_2"));
    label_2->setGeometry(QRect(250, 120, 151, 21));
    label_2->setStyleSheet(QStringLiteral(""));
    pushButton = new QPushButton(centralWidget);
    pushButton->setObjectName(QStringLiteral("pushButton"));
    pushButton->setGeometry(QRect(40, 230, 111, 23));
    pushButton_2 = new QPushButton(centralWidget);
    pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
    pushButton_2->setGeometry(QRect(190, 230, 151, 23));
    pushButton_2->setStyleSheet(QStringLiteral("QPushButton { color: red }"));
    MainWindow->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QStringLiteral("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 424, 26));
    MainWindow->setMenuBar(menuBar);
    mainToolBar = new QToolBar(MainWindow);
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    MainWindow->setStatusBar(statusBar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow* MainWindow) {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
    toolButton->setText(QApplication::translate("MainWindow", "...", 0));
    label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
    pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
  } // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
