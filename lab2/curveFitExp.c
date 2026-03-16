#include<stdio.h>
#include<math.h>

void expCurveFit(int n, float x[], float y[]){
    float sumX=0, sumX2=0, sumY=0, sumXY=0;
    float a, A, b;
    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumX2 += ( x[i] * x[i] );
        sumY += log(y[i]);
        sumXY += ( x[i] * log(y[i]) );
    }
    b = ( n * sumXY - sumX * sumY ) / ( n * sumX2 - sumX * sumX );
    //b needs to be calculated 1st otherwise garbage value of b will be in a's calculation
    A = ( sumY - b * sumX ) /n;
    a = exp(A);

    printf("The exponential curve fit is: y = %.2f * e^%.2fx\n", a, b);
    
}

int main(){
    float x[] = {0, 1, 2, 3};
    float y[] = { 100, 150, 220, 330};
    int n = 4;
    expCurveFit(n, x, y);
    return 0;
}