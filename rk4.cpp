#include <iostream>
#include <cmath>
#include <fstream>

const double k= 100;
const double m= 2;
const double lambda= 1;
const double delta_t=0.01;
const double g= 0.001;


double f0(double t, double y0, double y1)
{
    return y1;
}

double f1(double t, double y0, double y1)
{
    return -(k/m)*pow(y0,lambda);
}

double f2(double t, double y0, double y1)
{
    return -y1*g;
}

void rk4(double t, double h, double &y0, double &y1, double &yf)
{
    double k10, k11, k12, k20, k21, k22, k30, k31, k32, k40, k41, k42;
    k10 = h*f0(t, y0, y1);
    k11 = h*f1(t, y0, y1);
    k12 = h*f2(t, y0, y1);
    k20 = h*f0(t+h/2, y0 + k10/2, y1 + k11/2);
    k21 = h*f1(t+h/2, y0 + k10/2, y1 + k11/2);
    k22 = h*f2(t+h/2, y0 + k10/2, y1 + k11/2);
    k30 = h*f0(t+h/2, y0 + k20/2, y1 + k21/2);
    k31 = h*f1(t+h/2, y0 + k20/2, y1 + k21/2);
    k32 = h*f2(t+h/2, y0 + k20/2, y1 + k21/2);
    k40 = h*f0(t + h, y0 + k30, y1 + k31);
    k41 = h*f1(t + h, y0 + k30, y1 + k31);
    k42=  h*f2(t + h, y0 + k30, y1 + k31);

    y0 += (1.0/6.0)*(k10 + 2*k20 + 2*k30 + k40);
    y1 += (1.0/6.0)*(k11 + 2*k21 + 2*k31 + k41);
    yf += (1.0/6.0)*(k12 + 2*k22 + 2*k32 + k42);
}

int main(void)
{
    double x, v, time, xf;
    int progress;
    progress= 1;
    x = 1;
    v = 0;
    xf= 0;
    std::ofstream file("data_rk4.dat");
    for(time = 0; time <= 10; time += delta_t) 
    {
        file<< time << " " << x << " " << v<< " "<< xf << std::endl;
        rk4(time, delta_t, x, v, xf);
    }
    return 0;
}