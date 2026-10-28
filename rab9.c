#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#define ROW 9        /* размер таблицы Пифагора */
#define COL 9
#define V_ROW 4      /* размер таблицы варианта 1 */
#define V_COL 6

int multiply(int row, int col);
int pattern_value(int row, int col);
int count_digits(long long num);
int count_digit(long long num, int digit);

int main(void)
{
    int row, col;
    long long number;
    int digits, threes;
    char answer;

    setlocale(LC_ALL, "");

    /* Задание 1. Таблица Пифагора */
    printf(" Задание 1. Таблица умножения \n");
    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= COL; col++)
            printf("%5d", multiply(row, col));
        printf("\n");
    }
    printf("\n");

    /* Задание 1.2. Левый нижний треугольник */
    printf(" Задание 1.2. Левый нижний треугольник \n");
    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= row; col++)
            printf("%5d", multiply(row, col));
        printf("\n");
    }
    printf("\n");

    /* Задание 1.3. Печать чисел в заданном виде (вариант 1) */
    printf(" Задание 1.3. Вариант 1 \n");
    for (row = 1; row <= V_ROW; row++)
    {
        for (col = 1; col <= V_COL; col++)
            printf("%3d", pattern_value(row, col));
        printf("\n");
    }
    printf("\n");

    /*  Задание 2. Количество цифр 3 в числе (вариант 1) */
    printf(" Задание 2. Количество цифр 3 в числе \n");
    do
    {
        printf("Введите целое число: ");
        scanf("%lld", &number);

        digits = count_digits(number);
        threes = count_digit(number, 3);

        printf("Всего цифр в числе: %d\n", digits);
        printf("Количество цифр 3: %d\n", threes);

        printf("Продолжить? (Да - y, нет - n): ");
        scanf(" %c", &answer);
    } while (answer == 'y' || answer == 'Y');

    return 0;
}

int multiply(int row, int col)
{
    int result;
    result = row * col;
    return result;
}

/* Число для позиции (row, col) таблицы варианта 1: во всех ячейках 5 */
int pattern_value(int row, int col)
{
    int value;
    value = 5;
    return value;
}

int count_digits(long long num)
{
    int k = 0;

    if (num < 0)
        num = -num;

    do
    {
        k++;
        num /= 10;
    } while (num != 0);

    return k;
}

int count_digit(long long num, int digit)
{
    int k = 0;

    if (num < 0)
        num = -num;

    do
    {
        if (num % 10 == digit)
            k++;
        num /= 10;
    } while (num != 0);

    return k;
}