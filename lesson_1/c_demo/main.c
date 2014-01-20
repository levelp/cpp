#include <stdio.h>
#include <stdlib.h>
//#include <conio.h> // функция getch()

// Функции
int myFunction(){
    return 10;
}

int globalVariable = 21;

int main() // Основная функция программы
{
    printf("Hello world!\n"); // 13  13,10
    int c; // Обьявление переменной
    scanf("%d", &c); // Вводим с клавиатуры
    //getch(); // Ожидаёт нажатие клавиши и возвращает её ASCII код
    return 0;
}
