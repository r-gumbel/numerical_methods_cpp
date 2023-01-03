//===========================================================================
// Integration of a single variable function using composite simpson's rule
// Test function in this case will be a simple quadratic (x-2)**2
// User supplies inputs. Four different values of step size dx will print to
// stdout: dx = 1, dx = 0.1, dx = 0.01, dx = 0.001 -- Along with relative
// error associated with each
//===========================================================================
#include <iostream>
#include <cmath>
using namespace std;

double f(double x);
double antiF(double x);
double simpsons(double xmin, double xmax, double dx, int N);
double exact(double xmin, double xmax, double area);

int main()
{
    int i, N;
    double xmin, xmax, dx, area, error;

    cout << "Enter lower bound xmin:\n";
    cin  >> xmin;
    cout << "Enter upper bound xmax:\n";
    cin  >> xmax;

    cout << "======================================================================\n";
    cout << "\tdx" << "\tN" << "\tarea" << "    \terror%\n";
    cout << "======================================================================\n";

    for(i=0;i<=3;i++)
    {
        dx = pow(10.0,-i);
        N  = (xmax - xmin) / dx;
        area  = simpsons(xmin, xmax, dx, N);
        error = exact(xmin, xmax, area);
        cout << "\t" << dx << "\t" << N << "\t" << area << "\t\t" << error << "\n";
    }
    return 0;
}

//----------------------------------------------------------------------------------------
//  FUNCTION TO BE INTEGRATED, i.e. f(x) = (x-2)^2
//----------------------------------------------------------------------------------------
    double f(double x)
    {
        return( (x - 2.0) * (x - 2.0) );
    }

//---------------------------------------------------------------------------------------
//  ANTI-DERIVATIVE OF f(x), FOR CALCULATION OF RELATIVE ERROR
//---------------------------------------------------------------------------------------
    double antiF(double x)
    {
        return ( 1.0/3.0 * x*x*x - 2.0 * x*x + 4.0 * x );
    }

//---------------------------------------------------------------------------------------
//  PROCEDURE THAT USES SIMPSONS RULE TO CALCULATE A DEFINITE INTEGRAL FOR A SPECIFIED
//  STEP SIZE (dx), NUMBER OF POINTS (N), UPPER AND LOWER BOUNDS (xmin and xmax)
//---------------------------------------------------------------------------------------
    double simpsons(double xmin, double xmax, double dx, int N)
    {
        int i;
        double A;

        A = f(xmin) + f(xmax);
        for(i=2;i<=N-1;i++)
        {
            if (i%2 == 0)
                A = A + 4.0 * f(xmin + i*dx);
            else
                A = A + 2.0 * f(xmin + i*dx);
        }
        A = dx/3.0 * A;
        return(A);
    }
//-------------------------------------------------------------------------------------
//   PROCEDURE TO CALCULATE ERROR AT SPECIFIED STEP-SIZE (dx)
//-------------------------------------------------------------------------------------
    double exact(double xmin, double xmax, double area){
        double err;
        err = antiF(xmax) - antiF(xmin);         // Calculate relative error of simpsons
        err = fabs(err - area) / fabs(err);      // rule method at step size dx
        return (err);
    }
