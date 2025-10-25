#include <iostream>
#include <vector>
#include "shockStrengthData.hpp"
using namespace std;

int main()
{
    vector<double> init = {66500, 298, 652500, 298};
    shock test;
    waveProperties shockWave;
    double dt, t, totalTime;
    double xl, xr, x_shock, x_diaphragm, dx;

    xl = -10000;
    xr = 30000;
    x_shock = x_diaphragm = 0;

    totalTime = 8;
    dt = 0.05;
    t = 0;

    test.initialConditions(init);

    // cout << test.p2 << "\n";
    // cout << test.W << " " << test.Wr << " " << test.up << "\n";


    while(t <= totalTime)
    {
        x_shock = test.compWave.speed*t;

        if(x_shock > xr)
        {
            test.shockReflection();
            x_shock -= 2*xr;
        }

        if(test.compWave.speed > 0)
        {

        }
        else
        {

        }

        t += dt;
    }

    return 0;
}