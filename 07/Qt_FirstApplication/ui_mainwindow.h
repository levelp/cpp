/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget* centralWidget;
  QFormLayout* formLayout;
  QLabel* strLabel1;
  QLineEdit* strEdit1;
  QLineEdit* strEdit2;
  QLabel* resultLabel;
  QLineEdit* resultEdit;
  QPushButton* concatButton;
  QLabel* strLabel2;
  QVBoxLayout* verticalLayout;
  QMenuBar* menuBar;
  QToolBar* mainToolBar;
  QStatusBar* statusBar;

  void setupUi(QMainWindow* MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QStringLiteral("MainWindow"));
    MainWindow->resize(544, 369);
    QFont font;
    font.setFamily(QStringLiteral("Verdana"));
    font.setPointSize(14);
    MainWindow->setFont(font);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    formLayout = new QFormLayout(centralWidget);
    formLayout->setSpacing(6);
    formLayout->setContentsMargins(11, 11, 11, 11);
    formLayout->setObjectName(QStringLiteral("formLayout"));
    strLabel1 = new QLabel(centralWidget);
    strLabel1->setObjectName(QStringLiteral("strLabel1"));

    formLayout->setWidget(0, QFormLayout::LabelRole, strLabel1);

    strEdit1 = new QLineEdit(centralWidget);
    strEdit1->setObjectName(QStringLiteral("strEdit1"));

    formLayout->setWidget(0, QFormLayout::FieldRole, strEdit1);

    strEdit2 = new QLineEdit(centralWidget);
    strEdit2->setObjectName(QStringLiteral("strEdit2"));

    formLayout->setWidget(1, QFormLayout::FieldRole, strEdit2);

    resultLabel = new QLabel(centralWidget);
    resultLabel->setObjectName(QStringLiteral("resultLabel"));

    formLayout->setWidget(4, QFormLayout::LabelRole, resultLabel);

    resultEdit = new QLineEdit(centralWidget);
    resultEdit->setObjectName(QStringLiteral("resultEdit"));

    formLayout->setWidget(4, QFormLayout::FieldRole, resultEdit);

    concatButton = new QPushButton(centralWidget);
    concatButton->setObjectName(QStringLiteral("concatButton"));
    QFont font1;
    font1.setFamily(QStringLiteral("Tahoma"));
    font1.setPointSize(20);
    font1.setBold(true);
    font1.setWeight(75);
    concatButton->setFont(font1);

    formLayout->setWidget(3, QFormLayout::SpanningRole, concatButton);

    strLabel2 = new QLabel(centralWidget);
    strLabel2->setObjectName(QStringLiteral("strLabel2"));

    formLayout->setWidget(1, QFormLayout::LabelRole, strLabel2);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

    formLayout->setLayout(5, QFormLayout::LabelRole, verticalLayout);

    MainWindow->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QStringLiteral("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 544, 29));
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
    strLabel1->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\272\320\260 1:", 0));
    strEdit1->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\272\320\260 1", 0));
    strEdit2->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\272\320\260 2", 0));
    resultLabel->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", 0));
    concatButton->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\272\320\260\321\202\320\265\320\275\320\260\321\206\320\270\321\217", 0));
    strLabel2->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\272\320\260 2:", 0));
  } // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
