#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <math.h>

double sqrFunc(double d) {
  try {
    if(d < 0)
      throw QString("Square root: x = %1 < 0").arg(d);

    return sqrt(d);
  } catch(QString str) {
    qDebug() << str;
    throw QString("Error in sqrFunc");
    //throw 2;
  }
}
/*
void f3(){
  int localVarF3;
  try {
    f2();
  } catch(QString str){
    qDebug() << "QString: " << str;
  }
  catch (int param) {
    qDebug() << "int exception: " << param;
  }
  catch (char param) {
    qDebug() << "char exception" << param;
  }
} */


/*
bool myFunction(){

  if(что-то не так)
    return false;

  return true;
} */

double div1(int a, int b) {
  if(b == 0)
    throw QString("На ноль делить нельзя!");

  return a / (double)b;
}

void div2(int a, int b) {
  try {
    qDebug() << div1(a, b);
  } catch(QString s) {
    // qDebug() << "Error: " << s;
  }
}

void f2() {
  qDebug() << "f2 before f1() call";
  div2(2, 3);
  div2(4, 0);
  qDebug() << "f2 after f1() call";
}

int main(int argc, char* argv[]) {
  try {
    f2();
  } catch(QString s) {
    qDebug() << "Catch " << s;
  }

  /* ifstream in("")
  if(!in.good()){
  }
  while(!in.eof()){
    ...
  } */

  /* sqrFunc(-2);
   try{
     f3();
   }
   catch (...) { qDebug() << "default exception"; } */
  return 0;
}
