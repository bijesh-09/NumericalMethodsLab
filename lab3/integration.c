#include<stdio.h>

float f(float x){
    return 1 / (1 + x);
}

float trapezoid(int n, float h, float a, float b, float sum){
    for (int i = 1; i < n; i++)
    {
        sum += f(a + i * h);
    }
    
    return (h/2 * (f(a) + f(b) + 2 * sum));
}

void romberg(float a, float b){
    float h1 = (b - a) / 2;
    float I1 = trapezoid(2, h1, a, b, 0);

    float h2 = (b - a) / 4;
    float I2 = trapezoid(4, h2, a, b, 0);

    float h3 = (b - a) / 8;
    float I3 = trapezoid(8, h3, a, b, 0);

    float I4 = (4 * I2 - I1) / 3; 
    float I5 = (4 * I3 - I2) / 3; 

    float I = (4 * I5 - I4) / 3;
    printf("Romberg Integration: %f\n", I);

}

int main(){
    float a = 0, b = 1, sum = 0, h;
    int n = 6;
    h = (b-a)/n;

    // Trapezoidal Rule
    float result = trapezoid(n, h, a, b, sum); 
    printf("Trapezoid: %f\n", result);

    //Simpson's 1/3 Rule (Requires n to be even)
    sum = f(a) + f(b);
    for (int i = 1; i < n; i++)
        sum += (i % 2 == 0) ? 2 * f(a + i * h) : 4 * f(a + i * h);
    printf("Simpson 1/3: %f\n", (h / 3) * sum);

    //Simpson's 3/8 Rule (Requires n to be multiple of 3)
    sum = f(a) + f(b);
    for (int i = 1; i < n; i++)
        sum += (i % 3 == 0) ? 2 * f(a + i * h) : 3 * f(a + i * h);
    printf("Simpson 3/8: %f\n", (3 * h / 8) * sum);

    //Romberg Integration
    romberg(a, b);

}