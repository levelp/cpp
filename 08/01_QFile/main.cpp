/// Работа с файлами в Qt
/// =====================
/// Работа с файлами при помощи QFile
#include <QCoreApplication>
#include <QString>
#include <QFile> // Подключаем библиотеку c QFile
#include <QTextStream>
#include <QDebug>
#include <assert.h>

typedef unsigned char MyType;

int main() {
  ///-->
  // Выводить в текстовый файл с помощью Qt
  QFile file("qt_output.txt"); // Имя файла
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  // QIODevice::WriteOnly - создаём файл для записи
  // QIODevice::Text - к выводу применяются правила
  //   для текстового файла
  // QIODevice::ReadOnly - файл только для чтения
  // QIODevice::Append - добавляем (дописываем) в конец файла
  // QIODevice::ReadWrite - и читаем и пишем
  // QIODevice::Unbuffered - не пользоваться буфером для ввода/вывода

  // Аналог iostream из STL
  QTextStream out(&file); // Передаём указатель на файл
  out.setCodec("UTF-8"); // Задаём кодировку для записи
  // Выводим текст в поток (аналогично cout)
  out << QString("Любой текст!") << endl;
  out << QString("2 * 3 = ") << (2 * 3) << endl;
  out << 2 + 2 + 3 << QString(" Текст ") << endl;

  file.close();

  // Теперь прочитаем всё что записали
  QFile inFile("qt_output.txt");
  inFile.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream in(&inFile);
  // Читаем целую строку из файла
  QString str = in.readLine();
  qDebug() << str;

  inFile.close(); // Закрываем файл

  // Открываем файл второй раз и дописываем текст
  QFile f3("qt_output.txt");

  if(!f3.open(QIODevice::Append | QIODevice::Text)) {
    qDebug() << f3.errorString();
    return -1;
  }

  QTextStream out3(&f3);
  out3.setCodec("UTF-8");
  out3 << QString("Дописываем ещё текст") << endl;
  f3.close();
  ///<--

  QFile fbin("qt_output.bin");
  fbin.open(QIODevice::WriteOnly);

  // Создаём массив из N целых чисел
  const int N = 256;
  MyType A[N];
  for(int i = 0; i < N; ++i)
    A[i] = i;

  fbin.write((char*)A, sizeof(A));
  fbin.close();


  QFile fbin2("qt_output.bin");
  fbin2.open(QIODevice::ReadOnly);
  MyType B[N];
  fbin2.read((char*) B, sizeof(B));

  for(int i = 0; i < N; ++i)
    assert(B[i] == i);

  fbin2.close();

  return 0;
}
