#include <iostream>
#include <cmath>
using namespace std;

float gx(float x)
{
    return 2 / (x + 1);
}

int main()
{
    float err = 0.0001;
    int count = 0;
    float x0, x1;
    // let fx = x*x + x -2;
    cout << "ENter initial guess x0: ";
    cin >> x0;
    do
    {
        x1 = gx(x0);
        cout << "x0\t" << "x1" << endl;
        cout << x0 << "\t" << x1 << endl;
        x0 = x1;
        count++;
    } while (fabs((x1 - x0) / x1) > err);
    cout << "Root = " << x0 << endl;
    cout << "No. of iterations = " << count << endl;
    return 0;
}