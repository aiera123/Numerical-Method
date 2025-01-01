#include <stdio.h>
#include <conio.h>
int main() {
int n;
printf("Enter the number of data points: ");
scanf("%d", &n);
double x[n], y[n], Sx = 0, Sx2 = 0, Sx3 = 0, Sx4 = 0, Sy = 0, Sxy = 0, Sx2y = 0;
printf("Enter the x and y values:\n");
for (int i = 0; i < n; i++) {
printf("x[%d]: ", i); scanf("%lf", &x[i]);
printf("y[%d]: ", i); scanf("%lf", &y[i]);
Sx += x[i];
Sx2 += x[i] * x[i];
Sx3 += x[i] * x[i] * x[i];
Sx4 += x[i] * x[i] * x[i] * x[i];
Sy += y[i];
Sxy += x[i] * y[i];
Sx2y += x[i] * x[i] * y[i];
}
double det = n * (Sx2 * Sx4 - Sx3 * Sx3) - Sx * (Sx * Sx4 - Sx2 * Sx3) + Sx2 * (Sx * Sx3 -
Sx2 * Sx2);
double a = (Sy * (Sx2 * Sx4 - Sx3 * Sx3) - Sx * (Sxy * Sx4 - Sx3 * Sx2y) + Sx2 * (Sxy * Sx3
- Sx2y * Sx2)) / det;
double b = (n * (Sxy * Sx4 - Sx3 * Sx2y) - Sy * (Sx * Sx4 - Sx2 * Sx3) + Sx2 * (Sx * Sx2y -
Sxy * Sx2)) / det;
double c = (n * (Sx2 * Sx2y - Sxy * Sx3) - Sx * (Sx * Sx2y - Sxy * Sx2) + Sy * (Sx * Sx3 -
Sx2 * Sx2)) / det;
printf("Fitted quadratic equation: y = %.2lf + %.2lf*x + %.2lf*x^2\n", a, b, c);
return 0;
getch();
}
