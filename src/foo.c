#include "foo.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES

float circle(float r, float* p, float* s)
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
int isitnum(char* n, int* f)
{
    *f = 0;
    if (n[strlen(n) - 1] == '\n')
        n[strlen(n) - 1] = 0;
    for (int i = 0; n[i]; ++i)
        if (!(isdigit(n[i]))) {
            return 0;
        }
    *f = atof(n);
    return (1);
}
int isitfl(char* n, float* f)
{
    int flag = 0;
    *f = 0;
    if (n[strlen(n) - 1] == '\n')
        n[strlen(n) - 1] = 0;
    for (int i = 0; n[i]; ++i) {
        if (n[i] == ',') {
            return 0;
        }
        if (n[i] == '.') {
            i += 1;
            flag += 1;
        }
        if (!(isdigit(n[i])) || flag > 1) {
            return 0;
        }
    }
    *f = atof(n);
    return 1;
}
