#include <iostream>
#include <cmath>
#include <fstream>

const double k=100;
const double m= 2;
const double lambda= 1;


double f0(double t)
{
    return cos(t);
}

double f1(double t)
{
    return -(k/m)*pow(sin(t),lambda);
}

void euler(double t, double h, double &x0, double &v0)
{
    x0+=h*f0(t);
    v0+=h*f1(t);
}
    

int main(void)
{
    double x0= 0,v0=0, t= 0, h= 0.01;
    std::ofstream file("data_3");
    for (int i=0; i<1000;i++)
    {
        file<<x0<<" "<<v0<<" "<<t<<std::endl;
        t+=h;
        euler(t,h,x0,v0);
    }
    file.close();
    return 0;
}

