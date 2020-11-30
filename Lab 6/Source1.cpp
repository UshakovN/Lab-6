//������� 2. �������� �������, ������� � ����� x ������������� 0 � n ���, 
//����������� ������ �� ������� p, ��������� ���� �������� ��� ���������.

#include <cstdio>
#include <locale.h>
#pragma warning (disable: 4996)
#pragma warning (disable: 6387)

void output_32bit(FILE* f, int x, int size) {
    for (int i = size * 8; i > 0; --i) {
        fprintf(f, "%d", (x & (1 << (i - 1))) ? 1 : 0);
        printf("%d", (x & (1 << (i - 1))) ? 1 : 0);
    }
    fprintf(f, "\n\n"); printf("\n\n");
}

void output_bit(FILE* f, int x, int i) {
    if (i <= 32 && i > 0) {
        fprintf(f, "%d", (x & (1 << (i - 1))) ? 1 : 0);
        printf("%d", (x & (1 << (i - 1))) ? 1 : 0);
        output_32bit(f, x, --i);
    }
    fprintf(f, "\n\n"); printf("\n\n");
}


unsigned int change_mask(int x, int n, int p) {
    unsigned int result;
    if (((p < n)) || ((n >= sizeof(x) * 8)) || (n <= 0) || (p <= 0)) { result = -1; }
    else {
        x &= ~(((1 << (p - 1)) - 1) - ((1 << (p + n - 1)) - 1));
        result = x;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int select, n, p, x, x_changed;
    bool flag = true;
    FILE* input, * log;

    while (flag) {
        printf("1: �������� log-����. \n");
        printf("2: ������ ������. \n");
        printf("3: ���������� ������ ���������. \n");
        printf("�����: ");
        scanf_s("%d", &select);
        switch (select) {

        case (1):
            fopen_s(&log, "log.txt", "wt");
            fclose(log);
            fopen_s(&log, "log.txt", "at");
            fprintf(log, "log-���� ������. \n");
            fclose(log);
            break;

        case(2):
            fopen_s(&input, "input.txt", "rt");
            fopen_s(&log, "log.txt", "at");
            fprintf(log, "������ ����� x �� �����. \n");
            fscanf_s(input, "%d", &x);
            fprintf(log, "����� ��������� ����� x: %d \n", x); printf("%d \n", x);
            fprintf(log, "��������� ����� ��������� ����� x: ");
            output_32bit(log, x, sizeof(x));
            printf("������� ���������� ��� n � ������� p, ������ �� ������� ������� ���������� 0. \n");
            scanf_s("%d %d", &n, &p);
            x_changed = change_mask(x, n, p);
            if (x_changed != -1) {
                fprintf(log, "����� ����������� ����� x: %d \n", x_changed); printf("%d \n", x_changed);
                fprintf(log, "��������� ����� ����������� ����� x: ");
                output_32bit(log, x_changed, sizeof(x_changed));
            }
            else { printf("������������ �������� n � p. \n"); }
            fprintf(log, "\n"); fclose(input); fclose(log);
            break;

        case(3):
            flag = false;
            fopen_s(&log, "log.txt", "a");
            fprintf(log, "���������� ������ ���������. \n");
            fclose(log);
            break;

        default:
            printf("������� ���������� ��������. \n");
            break;
        }
    }
    return(0);
}

/*
unsigned int change_mask(int x, int n, int p) {
    unsigned int result;
    if (((p > n)) || ((n >= sizeof(x) * 8)) || (n <= 0) || (p <= 0)) { result = -1; }
    else {
        x &= ~(((1 << (p + n - 1)) - 1) - ((1 << (p - 1)) - 1));
        result = x;
    }
    return result;
}
*/