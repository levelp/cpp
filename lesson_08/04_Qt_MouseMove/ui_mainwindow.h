/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget* centralWidget;
  QLabel* label;
  QPushButton* yesButton;
  QPushButton* noButton;
  QStatusBar* statusBar;

  void setupUi(QMainWindow* MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QStringLiteral("MainWindow"));

    MainWindow->resize(817, 333);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    label = new QLabel(centralWidget);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(QRect(40, 40, 611, 51));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
    label->setSizePolicy(sizePolicy);
    QFont font;
    font.setFamily(QStringLiteral("Verdana"));
    font.setPointSize(24);
    label->setFont(font);
    label->setScaledContents(false);
    label->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignVCenter);
    yesButton = new QPushButton(centralWidget);
    yesButton->setObjectName(QStringLiteral("yesButton"));
    yesButton->setGeometry(QRect(200, 130, 81, 41));
    QFont font1;
    font1.setFamily(QStringLiteral("Verdana"));
    font1.setPointSize(20);
    yesButton->setFont(font1);
    noButton = new QPushButton(centralWidget);
    noButton->setObjectName(QStringLiteral("noButton"));
    noButton->setGeometry(QRect(330, 130, 75, 41));
    noButton->setFont(font1);
    MainWindow->setCentralWidget(centralWidget);
    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    MainWindow->setStatusBar(statusBar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow* MainWindow) {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
    label->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\262\320\276\320\273\321\214\320\275\321\213 \320\273\320\270 \320\262\321\213 \321\201\320\262\320\276\320\265\320\271 \320\267\320\260\321\200\320\277\320\273\320\260\321\202\320\276\320\271?", 0));
    yesButton->setText(QApplication::translate("MainWindow", "\320\224\320\260", 0));
    noButton->setText(QApplication::translate("MainWindow", "\320\235\320\265\321\202", 0));
  } // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
