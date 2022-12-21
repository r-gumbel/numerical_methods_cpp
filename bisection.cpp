// General bisection routine to find the root of a single variable function
#include <iostream>
#include <cmath>
using namespace std;

double func(double x);

int main()
{
    const double tolerance = pow(10.0,-15);
    double xmin, xmax;                       // end points of interval where search for root is performed
    double xmid;                             // midpoint of interval, i.e. xmid = 1/2 * (xmin + xmax)
    int i;

    xmin = 1.5; xmax = 5.0;                  // choose values such that f(xmin) * f(xmid) < 0
    i = 0;
    do                                       // iterate over bisection algorithm
    {
        xmid = 1.0/2.0 * (xmin + xmax);
        if (func(xmin) * func(xmid) > 0)
            xmin = xmid;
        else
            xmax = xmid;
        i++;
    } while(fabs(func(xmid)) >= tolerance);

    cout << "Bisection method converged to root x = " << xmid << " after " << i << " iterations\n";
    return 0;
}
//----------------------------------------------------------------------------------------------------
double func(double x)           // test function (x - 3)**3
{
    return (pow((x - 3),3));
}
