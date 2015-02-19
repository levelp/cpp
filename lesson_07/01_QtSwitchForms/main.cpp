#include "form1.h"
#include "form2.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  Form1 form1;
  form1.show();

  Form2 form2;

  // Форме один даём ссылку на форму 2
  form1.form2 = &form2;
  // Форме 2 даём ссылку на форму 1
  form2.form1 = &form1;

  return a.exec();
}
