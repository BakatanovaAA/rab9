#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

char square_symbol(int row, int col, char sym);

int main(void)
{
    char sym, c;
    int side;
    int row, col;
    int answer;

    setlocale(LC_ALL, "");

    do
    {
        printf("Введите символ, из которого будет строиться фигура: ");
        scanf(" %c", &sym);
        printf("Введите сторону квадрата (в символах): ");
        scanf("%d", &side);

        if (side < 1)
            printf("Ошибка: сторона должна быть больше 0\n");
        else
        {
            printf("Закрашенный квадрат:\n\n");
            for (row = 1; row <= side; row++)
            {
                for (col = 1; col <= side; col++)
                {
                    c = square_symbol(row, col, sym);
                    putchar(c);
                }
                printf("\n");
            }
        }

        printf("\nПродолжить? (Да - введите любое число, Нет - введите 0): ");
        scanf("%d", &answer);
    } while (answer != 0);

    return 0;
}

char square_symbol(int row, int col, char sym)
{
    char result;
    result = sym;
    return result;
}