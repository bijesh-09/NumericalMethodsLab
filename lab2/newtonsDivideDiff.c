#include <stdio.h>

void proterm_fn(int n, float xval, float x[], float proterm[])
{
    for (int i = 1; i < n; i++)
    {
        proterm[i - 1] = xval - x[i - 1];
    }
}

void divided_diff(int n, float x[], float y[][10])
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            y[j][i] = (y[j + 1][i-1] - y[j][i-1]) / (x[i+ j] - x[j]);
        }
    }
}

void print_diff(int n, float xval, float x[], float y[][10], float proterm[])
{
    float currentProtermAccumulator = 1;
    float finalResult = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            finalResult = y[0][i];
        }
        else
        {
            currentProtermAccumulator *= proterm[i - 1];
            finalResult += (currentProtermAccumulator * y[0][i]);
        }
    }
    printf("Given x values are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d\t%.2f\n",i, x[i]);
    }
    
    printf("The divided difference table is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%.2f\t", y[i][j]);
        }
        printf("\n");
    }
    
    printf("\nValue of function at %.2f is %.2f\n", xval, finalResult);
}

int main()
{
    int n = 4;
    float sum = 0, xval;
    float y[10][10], proterm[3];
    float x[] = {5, 6, 9, 11};

    printf("Enter the value of x to find the value of function at: ");
    scanf("%f", &xval);

    y[0][0] = 12;
    y[1][0] = 13;
    y[2][0] = 14;
    y[3][0] = 16;

    divided_diff(n, x, y);
    proterm_fn(n, xval, x, proterm);
    print_diff(n, xval, x, y, proterm);
    return 0;
}