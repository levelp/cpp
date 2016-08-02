#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Сумма: a + b = c
int sum(int a, int b);

// Факториал
long long factorial(int n);

// function - указатель на функцию возвращающую 1
typedef double (*dooubleFunc)(double x);

// Численное интегрирование
// Метод трапеций
double integral(dooubleFunc f, double from, double to);

#endif // FUNCTIONS_H
