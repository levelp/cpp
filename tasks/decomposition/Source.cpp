/*
* File: Source.cpp
* Author: Mikhail Goncharenko
*
* Created on 8 августа 2016 г., 12:18
*
* Программа считывает числовое значение из файла "decomposition.in" и
* производит разложение этого значения на слагаемые.
* Результат записывается в создаваемый программой файл "decomposition.out".
*
*/


#include <fstream>
#include <iostream>


int main() {
  //std::ofstream out("decomposition.out", std::ios::out | std::ios::trunc);
  std::ifstream in("decomposition.in");
  int number(0);
  int k(0); //счетчик количества вычитаемых символов
  int x(0); //счетчик выводимых элементов массива
  int l(0); //счетчик текущей позиции указателя элемента массива
  int z(0);
  int flag(0);
  int num[30] = { 0 };

  //in >> number;
  number = 4;

  while (k != number - 1) {
    if (k == 0) num[0] = number - k;

    else {
      //выполнять если предидущий элемент больше следующего
      if (num[l] > num[l + 1] && num[l] - num[l + 1] != 1) {
        //уменьшить предидущий элемент массива
        num[l] -= 1;
        //увеличить следующий элемент массива
        num[l + 1] += 1;
      } else

      {
        if (num[l] == num[l + 1] && num[l] == 1 && num[l + 1] == 1) {
          if (l != 0) {
            //если это последний вариант разложения текущего ряда
            //обнулить счетчик индекса текущего элемента массива
            l = 0;
            z++;
            if (num[l] > num[l + 1] + 1) num[l + 1] += 1;
            for (int i = (l + 1) + z; i < 30; i++) num[i] = 0;
            k++;
            x--;
            flag = 1;
          } else {
            //если это последний ряд
            num[number - 1] += 1;
          }
        } else {
          //уменьшить предидущий элемент
          num[l] -= 1;
          //увеличить следующий элемент
          num[l + 2] += 1;
          //увеличить на 1 счетчик индекса текущего элемента массива
          l++;
          x++;
        }
      }
    }
    if (!flag) {
      //цикл вывода элементов из массива
      std::cout << number << " = ";
      for (int i = 0; i <= x; i++) {
        if (i != 0) std::cout << " + ";
        std::cout << num[i];
      }
      std::cout << std::endl;

      if (num[l + 1] >= 2) {
        x++;
        l++;
      }
    }
    //определение количества выводимых элементов массива

    if (k == 0) {
      x++;
      k++;
    }
    flag = 0;
  }

  return 0;
}






















