#include "shockStrengthData.hpp"

void shock::initialConditions(vector<double> initialState)
{
    p1 = initialState[0];
    T1 = initialState[1];
    p4 = initialState[2];
    T4 = initialState[3];
    gamma = initialState[4];

    N = (gamma-1)*sqrt(gamma*R*T1)/sqrt(gamma*R*T4);
    D1 = 4*gamma*gamma;
    D2 = 2*gamma*(gamma-1);
    r = p4/p1;
    k = 2*gamma/(gamma-1);
    k_ = pow(r, 1/k);

    newtonRaphson();
    return;
}

double shock::f(double x)
{
    return (x - N*(x-1)/sqrt(D1+D2*(x-1)));
}

double shock::f_(double x)
{
    return (1 - N*((D1+D2*(x-1)) - D2*(x-1)/2)/pow(D1+D2*(x-1), 1.5));
}

void shock::newtonRaphson()
{
    double x_prev, x;

    do
    {
        x = x_prev - (f(x_prev)/f_(x_prev));
    } while (abs(x-x_prev) > 0.001);
    
    p2 = x;

    return;
}

void shock::stepCalculate()
{
    return;
}

void shock::storeinFile()
{
    return;
}