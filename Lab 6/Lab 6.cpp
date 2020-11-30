//Написать функцию, которая в числе x устанавливает 0 в n бит,
//находящихся слева от позиции p, остальные биты остаются без изменения.

#include <cstdio>
#include <locale.h>
#pragma warning (disable: 4996)
#pragma warning (disable: 6387)

void output_32bit(FILE* f, int x) {
    for (int i = 32 ; i > 0; --i) {
        fprintf(f, "%d", (x & (1 << (i - 1))) ? 1 : 0);
        printf("%d", (x & (1 << (i - 1))) ? 1 : 0);
    }
    fprintf(f, "\n\n"); printf("\n\n");
}

unsigned int change_mask(int x, int n, int p) {
    unsigned int result;
    if (((p > n)) || ((n >= 32)) || (n <= 0) || (p <= 0)) { result = -1; }
    else {
        x &= ~(((1 << (p + n - 1)) - 1) - ((1 << (p - 1)) - 1));
        result = x;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Rus");
    unsigned int x, x_changed;
    int select, n, p;
    bool flag = true; 
    FILE *input, *log;

    while (flag) {
        printf("1: Очистить log-файл. \n");
        printf("2: Решить задачу. \n");
        printf("3: Завершение работы программы. \n");
        printf("Выбор: ");
        scanf_s("%d", &select);
        switch (select) {

        case (1):
            fopen_s(&log, "log.txt", "wt");
            fclose(log);
            fopen_s(&log, "log.txt", "at");
            fprintf(log, "log-файл очищен. \n");
            fclose(log);
            break;

        case(2):
            fopen_s(&input, "input.txt", "rt");
            fopen_s(&log, "log.txt", "at");
            fprintf(log, "Чтение числа x из файла. \n\n");
            fscanf_s(input, "%d", &x);
            fprintf(log, "Вывод исходного числа x: %d \n", x); printf("%d \n", x);
            fprintf(log, "Побитовый вывод исходного числа x: ");
            output_32bit(log, x);

            printf("Введите количество бит n и позицию p, слева от которой следует установить 0. \n");
            scanf_s("%d %d", &n, &p);
            x_changed = change_mask(x, n, p);
            if (x_changed != -1) {
                fprintf(log, "Вывод измененного числа x: %d \n", x_changed); printf("%d \n", x_changed);
                fprintf(log, "Побитовый вывод измененного числа x: ");
                output_32bit(log, x_changed);
            }
            else { printf("Некорректные значения n и p. \n"); }
            fclose(input); fclose(log);
            break;

        case(3):
            flag = false;
            fopen_s(&log, "log.txt", "a");
            fprintf(log, "Завершение работы программы. \n");
            fclose(log);
            break;

        default:
            printf("Введите корректное значение. \n");
            break;
        }
    }
    return(0);
}

/*
void output_bit(FILE* f, int x, int i) {
    if (i <= 32 && i > 0) {
        fprintf(f, "%d", (x & (1 << (i - 1))) ? 1 : 0);
        printf("%d", (x & (1 << (i - 1))) ? 1 : 0);
        output_bit(f, x, --i);
    }
}
*/
