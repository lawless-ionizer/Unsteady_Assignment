#include "shockStrengthData.hpp"

void shock::initialConditions(vector<double> initialState)
{
    p1 = initialState[0];
    T1 = initialState[1];
    p4 = initialState[2];
    T4 = initialState[3];

    newtonRaphson();
    return;
}

void shock::newtonRaphson()
{
    double x_prev, x;
    double N, D1, D2, r, k, k_;

    x_prev = p4;
    N = (gamma-1)*sqrt(gamma*R*T1)/sqrt(gamma*R*T4);
    D1 = 4*gamma*gamma;
    D2 = 2*gamma*(gamma-1);
    r = p4/p1;
    k = 2*gamma/(gamma-1);
    k_ = pow(r, 1/k);

    // Lambda function f(x)
    auto f = [&]()
    {
        return (x - N*(x_prev-1)/sqrt(D1+D2*(x_prev-1)));
    };

    // Lambda function f'(x)
    auto f_ = [&]()
    {
        return (1 - N*((D1+D2*(x_prev-1)) - D2*(x_prev-1)/2)/pow(D1+D2*(x_prev-1), 1.5));
    };


    // Iterations
    do
    {
        x = x_prev - (f()/f_());
        x_prev = x;
    } while (abs(x-x_prev) > 0.001);
    
    p2 = x;

    return;
}

void shock::shockReflection()
{
    

    return;
}