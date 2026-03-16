#include<stdio.h>

void linearCurveFit(int n, float x[], float y[]){
    float sumX=0, sumX2=0, sumY=0, sumXY=0;
    float a, b;
    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumX2 += ( x[i] * x[i] );
        sumY += y[i];
        sumXY += ( x[i] * y[i] );
    }
    b = ( n * sumXY - sumX * sumY ) / ( n * sumX2 - sumX * sumX );
    //b needs to be calculated 1st otherwise garbage value of b will be in a's calculation
    a = ( sumY - b * sumX ) /n;

    printf("The linear curve fit is: y = %.2f + %.2fx\n", a, b);
    
}

int main(){
    float x[] = {1, 2, 3, 4, 5};
    float y[] = { 1.5, 2.1, 2.5, 3.0, 3.6};
    int n = 5;
    linearCurveFit(n, x, y);
    return 0;
}