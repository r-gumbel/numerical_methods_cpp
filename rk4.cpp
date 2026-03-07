#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

double f(double x, double y)
{
    return -x*y;
}

int main()
{
    int i, N;
    double xmin, xmax, dx, y0;
    double k1, k2, k3, k4;


    xmin = 0.;
    xmax = 1.;
    dx = 0.01;
    N = (xmax - xmin) / dx  + 1;

    double x[N], y[N];

    y[0] = 2.;
    for(i=0;i<N;i++)
    {
        x[i] = xmin + i*dx;
    }

    ofstream myfile("rk4.dat");

    myfile << x[0] << " " << y[0] << endl;
    
    for(i=0;i<N-1;i++)
    {
        k1 = f(x[i], y[i]);
        k2 = f(x[i] + dx/2., y[i] + k1*dx/2.);
        k3 = f(x[i] + dx/2., y[i] + k2*dx/2.);
        k4 = f(x[i] + dx, y[i] + k3*dx);

        y[i+1] = y[i] + dx/6.*(k1 + 2.*k2 + 2.*k3 + k4);
        myfile << x[i+1] << " " << y[i+1] << endl;
    }

    return 0;

}