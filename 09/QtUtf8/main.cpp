
#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>

QTextStream cin(stdin);
QTextStream cout(stdout);

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  QString string = "Привет, Мир!";
  QTextCodec* codec = QTextCodec::codecForName("CP866");

  // std::cout
  QByteArray encodedString = codec->fromUnicode(string);
  std::cout << "std::cout = " << encodedString.data() << std::endl;

  // TextStream
  cout.setCodec(codec);
  cout << "TextStream = " << string << "\n";
  cout.flush();

  // qDebug
  QTextCodec::setCodecForLocale(codec);
  qDebug() << "qDebug() = " << string;

  // Console r/w
  cout << "Enter a text: ";
  cout.flush();
  cin.setCodec(codec);
  QString inputStr;
  // Read data from a console
  cin >> inputStr;
  cout << "From a console = " << inputStr << endl;
  cout.flush();

  return a.exec();
}
