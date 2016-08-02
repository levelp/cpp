/// Шифрование / дешифрование файлов
///  - ввод из файла + вывод в другой файл
///  - ввод пароля
///  - написать алгоритм шифрации/дешифрации
///    XOR с паролем
///      This is test!
///  XOR 123123123123
///      'T' XOR '1'
#include <stdio.h>
#include <iostream>

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

void encodeFile(string input_file, char* output_file, string password) {
  Encoder encoder(password);
  cout << "\"" << input_file << "\" => \"" <<
       output_file << "\"  password = \"" << password << "\"" << endl;

  //  r - read - чтение
  //  w - write - запись
  //  a - append - добавление в конец
  // Открываю входной файл
  FILE* in = fopen(input_file.c_str(), "rb");

  if(!in) {
    cout << "Can't open \"" << input_file << "\"" << endl;
    throw string("Can't open file");
  }

  // Открываю выходной файл
  // wb - будем записывать по байтам
  FILE* out = fopen(output_file, "wb");

  if(!out) {
    cout << "Can't open \"" << output_file << "\"" << endl;
    throw string("Can't open file");
  }

  int i = 0; // Номер символа во входном файле
  int c; // note: int, not char, required to handle EOF

  while ((c = fgetc(in)) != EOF) { // standard C I/O file reading loop
    //putchar(c);
    fputc(encoder.encode(c, i), out); // Выводим символ в файл
    i++;
  }

  fclose(in); // Закрываем входной
  fclose(out); // Закрываем выходной файл
  cout << i << " bytes - OK" << endl;
}

// ArgC - argument's count
// ArgV - argument's values
// ArgV[0] - имя исполняемого файла
int main(int argc, char* argv[]) {
  //for(int i = 0; i < argc; i++){
  //  cout << "argv[" << i << "] = " << argv[i] << endl;
  //}
  if(argc < 4) {
    cout << "secret.exe <input_file> <output_file> <password>" << endl;
    cout << "Example: " << endl;
    cout << "   secret.exe input.data output.data 123" << endl;
    return -1;
  }

  char* input_file = argv[1];
  char* output_file = argv[2];
  string password = argv[3];

  encodeFile(input_file, output_file, password);

  // Сразу же пробуем расшифровать
  encodeFile(output_file, "test.data", password);

  return 0;
}
