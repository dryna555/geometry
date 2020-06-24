#include "foo.h"
#include <math.h>
#include <stdio.h>
#define _USE_MATH_DEFINES

int main()
{
    int colvo, i, j;
    printf("Введите количество окружностей\n");
    scanf("%d", &colvo);
    float x[colvo], y[colvo], r[colvo], p, s;
    int rez[colvo][colvo];
    for (i = 0; i < colvo; i++) {
        printf("Введите координаты центра окржности и его радиус:\n");
        printf("X = ");
        scanf("%f", &x[i]);
        printf("Y = ");
        scanf("%f", &y[i]);
        printf("R = ");
        scanf("%f", &r[i]);
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
        circle(x[i], y[i], r[i], &p, &s);
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
