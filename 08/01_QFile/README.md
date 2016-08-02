Работа с файлами в Qt
=====================
Работа с файлами при помощи QFile
``` cpp
  // Выводить в текстовый файл с помощью Qt
  QFile file("qt_output.txt");
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  // QIODevice::WriteOnly - создаём файл для записи
  // QIODevice::Text - к выводу применяются правила
  //   для текстового файла

  QTextStream out(&file);
  out.setCodec("UTF-8");
  out << QString("Любой текст!") << endl;
  out << QString("2 * 3 = ") << (2 * 3) << endl;
  out << 2 + 2 + 3 << " Текст " << endl;

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
  out3 << "Дописываем ещё текст" << endl;
  f3.close();
```

[main.cpp](main.cpp)

