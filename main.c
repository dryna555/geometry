#include <math.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
float circle(float x, float y, float r, float* p, float* s)
{
    float r2;
    *p = 2 * M_PI * r;
    r2 = pow(r, 2);
    *s = M_PI * r2;
    return 0;
}
int presecli(float x1, float y1, float r1, float x2, float y2, float r2)
{
    float d, sr;
    int f = 0;
    if ((x1 == x2) && (y1 == y2)) {
        f = 1;
    } else {
        d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        sr = r1 + r2;
        if ((d <= sr) && (d >= fabs(r1 - r2))) {
            f = 1;
        } else {
            f = 0;
        }
    }
    return f;
}

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
