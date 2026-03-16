#include <stdio.h>
#include <math.h>

// The function we want to differentiate: f(x) = x^3 + 2x^2
double f(double x) {
    return (x * x * x) + (2 * x * x);
}

int main() {
    double x, h = 0.01; // Step size (smaller h = more accuracy)
    double forward, backward, central, second_deriv;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // 1st Derivative: Forward Difference
    forward = (f(x + h) - f(x)) / h;

    // 1st Derivative: Backward Difference
    backward = (f(x) - f(x - h)) / h;

    // 1st Derivative: Central Difference (Most Accurate)
    central = (f(x + h) - f(x - h)) / (2 * h);

    // 2nd Derivative: Central Difference
    second_deriv = (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);

    printf("\n--- 1st Derivative Results ---\n");
    printf("Forward Difference:  %.4f\n", forward);
    printf("Backward Difference: %.4f\n", backward);
    printf("Central Difference:  %.4f\n", central);

    printf("\n--- 2nd Derivative Result ---\n");
    printf("Second Derivative:   %.4f\n", second_deriv);

    return 0;
}
