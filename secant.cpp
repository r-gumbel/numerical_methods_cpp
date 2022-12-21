//===================================================================================
// General secant method routine for finding the root of a single variable function
// Finds the root of sqrt(x+1) * sin(x) in the region of 0 < x < 2p
//===================================================================================
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double tolerance = pow(10.0, -15);
    double x0, x1, x2;
    double fx0, fx1, interval;
    bool rootFound = false;
    int i, N;

    x0 = 3.0; x1 = 4.0;       // Set initial estimate

    for(i = 1; i <= 500; i++) // Loop 500 times or until convergence is reached
    {
        fx0 = sqrt(x0 + 1.0) * pow(sin(x0),3);
        fx1 = sqrt(x1 + 1.0) * pow(sin(x1),3);
        x2  = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        interval = fabs(x2 - x1) / fabs(x1);

        if (interval <= tolerance)
        {
            N = i;
            rootFound = true;
            break;
        }

        x0 = x1;     // iterate variables for next loop
        x1 = x2;
    }

    if(rootFound = true)
        cout << "After " << N << " iterations, the root is " << x2 << "\n";
    else
        cout << "Secant method did not converge.\n";
    return 0;
}

