#include <stdio.h>
#include <conio.h>
int main() {
int n; // Number of data points
printf("Enter the number of data points: ");
scanf("%d", &n);
double x[n], y[n]; // Arrays to store x and y values
printf("Enter the equidistant x values:\n");
for (int i = 0; i< n; i++) {
scanf("%lf", &x[i]);
}
printf("Enter the corresponding y values:\n");
for (int i = 0; i< n; i++) {
scanf("%lf", &y[i]);
}
double h = x[1] - x[0]; // Common difference
double f[n][n]; // Divided differences
// Initialize the divided differences with y values
for (int i = 0; i< n; i++) {
f[i][0] = y[i];
}
// Compute divided differences
for (int j = 1; j < n; j++) {
for (int i = 0; i< n - j; i++) {
f[i][j] = (f[i+1][j-1] - f[i][j-1]) / (x[i+j] - x[i]);
}
}
// Interpolating polynomial evaluation
double x_interp; // The point where you want to interpolate
printf("Enter the value of x for interpolation: ");
scanf("%lf", &x_interp);
double result = f[0][0];
double term = 1.0;
for (int i = 0; i< n; i++) {
term *= (x_interp - x[i]);
result += f[0][i+1] * term;
}
printf("Interpolated value at x = %.2lf is %.6lf\n", x_interp, result);
return 0;
getch();
}
