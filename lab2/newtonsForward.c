#include<stdio.h>

int fact(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n * fact(n - 1);
}

void forward_diff(int n, float x[], float y[][10]){
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = y[j+1][i-1] - y[j][i-1];
        }
        
    }
    
}

void print_forward(int n, float xval, float x[], float y[][10]){
    float h,u;
    h = x[1] - x[0];
    u = ( xval - x[0] ) / h;
    float finalResult = 0;
    for (int i = 0; i < n; i++)
    {
        if (i==0)
        {
            finalResult = y[0][i];
        }
        else{
            finalResult += ( ( u * y[0][i] ) / fact(i) );
        }
        
    }
    printf("Given x values are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d\t%.2f\n",i, x[i]);
    }
    
    printf("The forward difference table is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%.2f\t", y[i][j]);
        }
        printf("\n");
    }

    printf("Value of function at %.2f is %.2f\n", xval, finalResult);
    
}

int main(){
    float x[] = {1891, 1901, 1911, 1921, 1931};
    float y[10][10];
    int n = 5;
    float xval = 1895;
    y[0][0] = 46;
    y[1][0] = 66;
    y[2][0] = 81;
    y[3][0] = 93;
    y[4][0] = 101;

    forward_diff(n, x, y);
    print_forward(n, xval, x, y);

    return 0;
}