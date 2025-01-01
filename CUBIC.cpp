#include <stdio.h>
void cubicSpline(int n, double x[], double y[], double a[], double b[], double c[], double d[]) {
double h[n - 1], alpha[n], l[n], mu[n], z[n];
for (int i = 0; i < n - 1; i++) h[i] = x[i + 1] - x[i];
for (int i = 1; i < n - 1; i++)
alpha[i] = (3 / h[i]) * (y[i + 1] - y[i]) - (3 / h[i - 1]) * (y[i] - y[i - 1]);
l[0] = 1; mu[0] = z[0] = 0;
for (int i = 1; i < n - 1; i++) {
l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
mu[i] = h[i] / l[i];
z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
}
l[n - 1] = 1; z[n - 1] = c[n - 1] = 0;
for (int j = n - 2; j >= 0; j--) {
c[j] = z[j] - mu[j] * c[j + 1];
b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
a[j] = y[j];
}
}
int main() {
int n = 4;
double x[] = {0, 1, 2, 3}, y[] = {1, 2, 0, 2};
double a[n], b[n - 1], c[n], d[n - 1];
cubicSpline(n, x, y, a, b, c, d);
printf("Spline coefficients:\n");
for (int i = 0; i < n - 1; i++)
printf("Interval [%lf, %lf]: a=%lf, b=%lf, c=%lf, d=%lf\n",
x[i], x[i + 1], a[i], b[i], c[i], d[i]);
return 0;
}
