#include "encryptthread.h"
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include <assert.h>

using namespace std;

class Encoder {
  string password; // Пароль для шифрования
 public:
  // В конструктор передаётся пароль для шифрования
  Encoder(string password) : password(password) {
  }
  int encode(int c, int i) {
    // Символ из пароля
    int passwordIndex = i % password.size();
    // Зашифрованный символ
    return c ^ password[passwordIndex];
  }
};

EncryptThread::EncryptThread(QObject* parent)
  : QThread(parent) {

}

long getFileSize(std::string filename) {
  struct stat stat_buf;
  int rc = stat(filename.c_str(), &stat_buf);
  return rc == 0 ? stat_buf.st_size : -1;
}

void EncryptThread::run() {
  string input_file(srcFileName.toStdString());
  string output_file(dstFileName.toStdString());

  Encoder encoder(password.toStdString());
  //cout << "\"" << input_file << "\" => \"" <<
  //     output_file << "\"  password = \"" << password << "\"" << endl;

  //  r - read - чтение
  //  w - write - запись
  //  a - append - добавление в конец
  // Открываю входной файл
  FILE* in = fopen(input_file.c_str(), "rb");

  // Получаем размер исходного файла
  int size = getFileSize(input_file);

  if(!in) {
    // cout << "Can't open \"" << input_file << "\"" << endl;
    throw string("Can't open file");
  }

  // Открываю выходной файл
  // wb - будем записывать по байтам
  FILE* out = fopen(output_file.c_str(), "wb");

  if(!out) {
    //std::cout << "Can't open \"" << output_file << "\"" << endl;
    throw string("Can't open file");
  }

  int i = 0; // Номер символа во входном файле
  int c; // note: int, not char, required to handle EOF

  // Предыдущие проценты
  int prevPercents = -1;
  while ((c = fgetc(in)) != EOF) { // standard C I/O file reading loop
    //putchar(c);
    fputc(encoder.encode(c, i), out); // Выводим символ в файл
    i++;

    // Процентов от файла
    int percents = (i * 100LL) / size;
    assert(percents <= 100);
    assert(percents >= 0);

    // Отправляем сигнал
    if(percents != prevPercents) {
      // Если проценты изменились
      emit percentsUpdated(percents);

      prevPercents = percents;
    }

    // 1 миллисекунда пауза
    // QThread::msleep(1);
  }

  fclose(in); // Закрываем входной
  fclose(out); // Закрываем выходной файл
  //cout << i << " bytes - OK" << endl;

  // progressBar->hide();
}
