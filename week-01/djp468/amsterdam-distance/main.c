#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846
int min(int a, int b) { return a < b ? a : b; }
int main() {
    int m, n, x1, y1, x2, y2;
    double r;
    if (scanf("%d %d %lf %d %d %d %d", &m, &n, &r, &x1, &y1, &x2, &y2) != 7) {
        return 1;
    };
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    double ax = PI * r * dx * (double)min(y1, y2) / (n * m);
    double ay = ((double)dy / n) * r;
    double a = ax + ay;
    double b = (y2 + y1) * (r / n);
    printf("%f\n", fmin(a, b));
    return 0;
}