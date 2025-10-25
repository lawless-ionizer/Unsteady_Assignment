#include "shockStrengthData.hpp"

void shock::initialConditions(vector<double> initialState)
{
    p1 = initialState[0];
    T1 = initialState[1];
    p4 = initialState[2];
    T4 = initialState[3];

    a1 = sqrt(gamma*R*T1);
    a4 = sqrt(gamma*R*T4);

    propertyCalculations();

    compWave.p_behind = p2;
    compWave.T_behind = T2;
    compWave.rho_behind = rho2;
    compWave.speed = W;
    compWave.speed_behind = up;

    return;
}

void shock::propertyCalculations()
{
    newtonRaphson();

    rho1 = p1/(R*T1);
    T2 = T1*p2*(((gamma+1)/(gamma-1) + p2/p1)/(1 + ((gamma+1)/(gamma-1))*p2/p1))/p1;
    rho2 = p2/(R*T2);
    a2 = sqrt(gamma*R*T2);
    Ms = sqrt((gamma+1)*(p2/p1 - 1)/(2*gamma) + 1);
    W = a1*Ms;
    up = W*(1 - rho1/rho2);
}

void shock::newtonRaphson()
{
    double x_prev, x;
    double N, D1, D2, r, k, k_;

    x_prev = p4/p1;
    N = (gamma-1)*a1/a4;
    D1 = 4*gamma*gamma;
    D2 = 2*gamma*(gamma+1);
    r = p4/p1;
    k = -2*gamma/(gamma-1);

    // Lambda function f(x_prev)
    auto f = [&]()
    {
        return x_prev*pow((1 - (N*(x_prev - 1))/sqrt(D1 + D2*(x_prev-1))),k) - r;
    };

    // Lambda function f'(x_prev)
    auto f_ = [&]()
    {
        return k*x_prev*pow((-N*(x_prev - 1)/sqrt(D1 + D2*(x_prev - 1)) + 1),k)*(0.5*D2*N*(x_prev - 1)/pow(D1 + D2*(x_prev - 1),1.5) - N/sqrt(D1 + D2*(x_prev - 1)))/(-N*(x_prev - 1)/sqrt(D1 + D2*(x_prev - 1)) + 1) + pow(-N*(x_prev - 1)/sqrt(D1 + D2*(x_prev - 1)) + 1, k);
    };


    // Iterations
    while (abs(f()) > 0.0001)
    {
        x = x_prev - (f()/f_());
        x_prev = x;
    }
    
    p2 = x*p1;

    return;
}

void shock::shockReflection()
{
    double a, Cp;
    a = sqrt(1 + 2*(gamma-1)*(Ms*Ms - 1)*(gamma + 1/(Ms*Ms))/((gamma+1)*(gamma+1)))*Ms/(Ms*Ms - 1);
    Cp = gamma*R/(gamma - 1);

    Mr = (1 + sqrt(4*a*a + 1))/(2*a);
    Wr = Mr*a2 - up;
    T5 = T2 - (Wr*up + up*up/2)/Cp;
    p5 = p2*pow(T5/T2, gamma/(gamma - 1));
    rho5 = rho2*pow(p5/p2,1/gamma);

    compWave.p_behind = p5;
    compWave.T_behind = T5;
    compWave.rho_behind = rho5;
    compWave.speed = Wr;
    compWave.speed_behind = 0;

    return;
}