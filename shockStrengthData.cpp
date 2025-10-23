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

    x_prev = 0.5;
    N = (gamma-1)*sqrt(gamma*R*T1)/sqrt(gamma*R*T4);
    D1 = 4*gamma*gamma;
    D2 = 2*gamma*(gamma-1);
    r = p4/p1;
    k = -2*gamma/(gamma-1);
    k_ = pow(r, 1/k);

    // Lambda function f(x)
    auto f = [&]()
    {
        return (pow(x_prev, 1/k) - N*(x_prev-1)*pow(x_prev,1/k)/sqrt(D1+D2*(x_prev-1)) - k_);
    };

    // Lambda function f'(x)
    auto f_ = [&]()
    {
        return 0.5*D2*N*pow(x_prev,1/k)*(x_prev - 1)/pow((D1 + D2*(x_prev - 1)),1.5) - N*pow(x_prev,1/k)/pow((D1 + D2*(x_prev - 1)),0.5) - N*pow(x_prev,1/k)*(x_prev - 1)/(k*x_prev*pow((D1 + D2*(x_prev - 1)),0.5)) + pow(x_prev,1/k)/(k*x_prev);
    };


    // Iterations
    x = x_prev - (f()/f_());
    // cout << x << "\n";
    while (abs(x-x_prev) > 0.0001)
    {
        x_prev = x;
        x = x_prev - (f()/f_());
        // cout << x << "\n";
    }
    
    p2 = x*p1;

    return;
}

void shock::shockReflection()
{
    

    return;
}