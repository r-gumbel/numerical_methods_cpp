// Integration of a single-variable function using composite trapezoidal method
#include <iostream>
#include <cmath>
using namespace std;

double func(double x);                      // Function to be integrated.  Test case is x**2
double exact(double x);                     // Exact value of anti-derivative to calculate error: 1/3 * x**3
double trap(int N, double dx, double x);    // Composite trapezoidal method procedure to perform integration

int main()
{
    int i, N;
    double xmin, xmax, dx, area, error;

    cout << "Enter integration bounds for test function f(x) == x^2\n";
    cout << "xmin = \n"; cin >> xmin;
    cout << "xmax = \n"; cin >> xmax;
    cout << "===========================================\n";
    cout << "\tdx" << "\tN" << "\tarea" << "\terror\n";
    cout << "===========================================\n";

    for(i = 0; i <= 3; i++)
    {
        dx = pow(10,-i);
        N  = (xmax - xmin ) / dx;
        area = trap(N, dx, xmin);
        error = fabs((exact(xmax) - exact(xmin)) - area) / fabs(exact(xmax) - exact(xmin));
        error = error * 100.0;
        cout << "\t"<< dx << "\t" << N << "\t" << area << "\t" << error << "\n";
    }

        cout << "===========================================\n";
}

double func(double x)
{
    return(pow(x,2));
}

double exact(double x)
{
    return(1.0/3.0 * pow(x,3));
}

double trap(int N, double dx, double x)
{
    int i;
    double area;

    area = 0.0;
    for(i = 0; i < N; i++)
    {
        area = area + dx * (func((x + (i)*dx + (i+1)*dx)/2.0));
    }
    return(area);
}
