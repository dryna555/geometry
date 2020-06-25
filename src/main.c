#include "foo.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#define _USE_MATH_DEFINES

int main()
{
    int colvo = 0, i, j;
    char n[100];
    printf("Введите количество окружностей\n");
    fgets(n, 100, stdin);
    while (isitnum(n, &colvo) == 0) {
        printf("Введите число\n");
        fgets(n, 100, stdin);
    }
    float x[colvo], y[colvo], r[colvo], p, s;
    int rez[colvo][colvo];
    for (i = 0; i < colvo; i++) {
        printf("Введите координаты центра окржности и его радиус:\n");
        printf("X = ");
        fgets(n, 100, stdin);
        printf("  area = %d\n", isitfl(n, &x[i]));
        while (isitfl(n, &x[i]) == 0) {
            printf("Введите число, разделяяя дробную часть точкой\n");
            fgets(n, 100, stdin);
        }
        printf("Y = ");
        fgets(n, 100, stdin);
        while (isitfl(n, &y[i]) == 0) {
            printf("Введите число, разделяяя дробную часть точкой\n");
            fgets(n, 100, stdin);
        }
        printf("R = ");
        fgets(n, 100, stdin);
        while (isitfl(n, &r[i]) == 0) {
            printf("Введите число, разделяяя дробную часть точкой\n");
            fgets(n, 100, stdin);
        }
        printf("\n");
    }
    for (i = 0; i < colvo; i++) {
        for (j = 0; j < colvo; j++) {
            rez[i][j] = 0;
            if (i != j) {
                rez[i][j] = presecli(x[i], y[i], r[i], x[j], y[j], r[j]);
            }
        }
    }
    for (i = 0; i < colvo; i++) {
        circle(r[i], &p, &s);
        printf("%d. circle(%f %f, %f)\n", i + 1, x[i], y[i], r[i]);
        printf("  perimeter = %f \n", p);
        printf("  area = %f \n", s);
        printf("  intersects:\n");
        for (j = 0; j < colvo; j++) {
            if (rez[i][j] == 1) {
                printf("     %d. circle\n", j + 1);
            }
        }
    }
}
