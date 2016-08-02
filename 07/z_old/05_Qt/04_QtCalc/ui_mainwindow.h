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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget* centralWidget;
  QVBoxLayout* verticalLayout;
  QLineEdit* display;
  QWidget* bottom;
  QLabel* state;
  QPushButton* B1;
  QPushButton* B2;
  QPushButton* B7;
  QPushButton* B4;
  QPushButton* PlusButton;
  QPushButton* B9;
  QPushButton* B0;
  QPushButton* B3;
  QPushButton* B5;
  QPushButton* ClearButton;
  QPushButton* PointButton;
  QLabel* memory;
  QPushButton* B6;
  QPushButton* B8;
  QMenuBar* menuBar;
  QToolBar* mainToolBar;

  void setupUi(QMainWindow* MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QStringLiteral("MainWindow"));

    MainWindow->resize(456, 278);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    verticalLayout = new QVBoxLayout(centralWidget);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    display = new QLineEdit(centralWidget);
    display->setObjectName(QStringLiteral("display"));
    QFont font;
    font.setFamily(QStringLiteral("Courier New"));
    font.setPointSize(25);
    font.setBold(true);
    font.setWeight(75);
    display->setFont(font);
    display->setLayoutDirection(Qt::LeftToRight);
    display->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    display->setReadOnly(false);

    verticalLayout->addWidget(display);

    bottom = new QWidget(centralWidget);
    bottom->setObjectName(QStringLiteral("bottom"));
    bottom->setMinimumSize(QSize(438, 178));
    bottom->setMaximumSize(QSize(16777215, 178));
    state = new QLabel(bottom);
    state->setObjectName(QStringLiteral("state"));
    state->setGeometry(QRect(300, 40, 111, 20));
    B1 = new QPushButton(bottom);
    B1->setObjectName(QStringLiteral("B1"));
    B1->setGeometry(QRect(10, 20, 41, 31));
    QFont font1;
    font1.setFamily(QStringLiteral("Verdana"));
    font1.setPointSize(16);
    B1->setFont(font1);
    B2 = new QPushButton(bottom);
    B2->setObjectName(QStringLiteral("B2"));
    B2->setGeometry(QRect(60, 20, 41, 31));
    B2->setFont(font1);
    B7 = new QPushButton(bottom);
    B7->setObjectName(QStringLiteral("B7"));
    B7->setGeometry(QRect(10, 100, 41, 31));
    B7->setFont(font1);
    B4 = new QPushButton(bottom);
    B4->setObjectName(QStringLiteral("B4"));
    B4->setGeometry(QRect(10, 60, 41, 31));
    B4->setFont(font1);
    PlusButton = new QPushButton(bottom);
    PlusButton->setObjectName(QStringLiteral("PlusButton"));
    PlusButton->setGeometry(QRect(170, 20, 41, 31));
    PlusButton->setFont(font1);
    B9 = new QPushButton(bottom);
    B9->setObjectName(QStringLiteral("B9"));
    B9->setGeometry(QRect(110, 100, 41, 31));
    B9->setFont(font1);
    B0 = new QPushButton(bottom);
    B0->setObjectName(QStringLiteral("B0"));
    B0->setGeometry(QRect(60, 140, 41, 31));
    B0->setFont(font1);
    B3 = new QPushButton(bottom);
    B3->setObjectName(QStringLiteral("B3"));
    B3->setGeometry(QRect(110, 20, 41, 31));
    B3->setFont(font1);
    B5 = new QPushButton(bottom);
    B5->setObjectName(QStringLiteral("B5"));
    B5->setGeometry(QRect(60, 60, 41, 31));
    B5->setFont(font1);
    ClearButton = new QPushButton(bottom);
    ClearButton->setObjectName(QStringLiteral("ClearButton"));
    ClearButton->setGeometry(QRect(240, 20, 41, 31));
    ClearButton->setFont(font1);
    PointButton = new QPushButton(bottom);
    PointButton->setObjectName(QStringLiteral("PointButton"));
    PointButton->setGeometry(QRect(170, 140, 41, 31));
    PointButton->setFont(font1);
    memory = new QLabel(bottom);
    memory->setObjectName(QStringLiteral("memory"));
    memory->setGeometry(QRect(340, 10, 71, 16));
    memory->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    B6 = new QPushButton(bottom);
    B6->setObjectName(QStringLiteral("B6"));
    B6->setGeometry(QRect(110, 60, 41, 31));
    B6->setFont(font1);
    B8 = new QPushButton(bottom);
    B8->setObjectName(QStringLiteral("B8"));
    B8->setGeometry(QRect(60, 100, 41, 31));
    B8->setFont(font1);

    verticalLayout->addWidget(bottom);

    MainWindow->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QStringLiteral("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 456, 21));
    MainWindow->setMenuBar(menuBar);
    mainToolBar = new QToolBar(MainWindow);
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

    retranslateUi(MainWindow);
    QObject::connect(B2, SIGNAL(clicked()), MainWindow, SLOT(on_digit_clicked()));
    QObject::connect(B3, SIGNAL(clicked()), MainWindow, SLOT(on_digit_clicked()));
    QObject::connect(B4, SIGNAL(clicked()), MainWindow, SLOT(on_digit_clicked()));
    QObject::connect(B5, SIGNAL(clicked()), MainWindow, SLOT(on_digit_clicked()));
    QObject::connect(B6, SIGNAL(clicked()), MainWindow, SLOT(on_digit_clicked()));
    QObject::connect(B7, SIGNAL(clicked()), MainWindow, SLOT(on_digit_clicked()));
    QObject::connect(B8, SIGNAL(clicked()), MainWindow, SLOT(on_digit_clicked()));
    QObject::connect(B9, SIGNAL(clicked()), MainWindow, SLOT(on_digit_clicked()));
    QObject::connect(B1, SIGNAL(clicked()), MainWindow, SLOT(on_digit_clicked()));
    QObject::connect(B0, SIGNAL(clicked()), MainWindow, SLOT(on_digit_clicked()));

    QMetaObject::connectSlotsByName(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow* MainWindow) {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
    display->setText(QApplication::translate("MainWindow", "0", 0));
    state->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\275\320\265 \320\267\320\260\320\264\320\260\320\275\320\276", 0));
    B1->setText(QApplication::translate("MainWindow", "1", 0));
    B2->setText(QApplication::translate("MainWindow", "2", 0));
    B7->setText(QApplication::translate("MainWindow", "7", 0));
    B4->setText(QApplication::translate("MainWindow", "4", 0));
    PlusButton->setText(QApplication::translate("MainWindow", "+", 0));
    B9->setText(QApplication::translate("MainWindow", "9", 0));
    B0->setText(QApplication::translate("MainWindow", "0", 0));
    B3->setText(QApplication::translate("MainWindow", "3", 0));
    B5->setText(QApplication::translate("MainWindow", "5", 0));
    ClearButton->setText(QApplication::translate("MainWindow", "C", 0));
    PointButton->setText(QApplication::translate("MainWindow", ".", 0));
    memory->setText(QApplication::translate("MainWindow", "0", 0));
    B6->setText(QApplication::translate("MainWindow", "6", 0));
    B8->setText(QApplication::translate("MainWindow", "8", 0));
  } // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
