#include <stdio.h>
#include <math.h>

float lagrange(float arrx[], float arrf[], float x, int n)
{
    float result = 0; // initializing result
    for (int i = 0; i < n; i++)
    {
        float numerator = 1;   // initializing numerator
        float denominator = 1; // initializing denominator

        for (int j = 0; j < n; j++)
        {
            if (i != j) // making sure the inteneded i is not equal to looping j
            {
                numerator *= x - arrx[j];
                denominator *= arrx[i] - arrx[j];
            }
        }

        result += (numerator / denominator) * arrf[i]; // without initilaizing result with 0, return value will be undefined
    }
    return result;
}

int main()
{
    float x;
    int n;
    float arrx[100], arrf[100];
    float fx;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter x0, x1, x2, ... xn-1: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arrx[i]);
    }
    printf("Enter fx0, fx1, fx2, ... fxn-1: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arrf[i]);
    }
    printf("Enter x: ");
    scanf("%f", &x);
    fx = lagrange(arrx, arrf, x, n);
    printf("The value of fx is: %.2f", fx);

    return 0;
}