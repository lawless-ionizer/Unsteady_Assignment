#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include "shockStrengthData.hpp"
#include "expansionReflection.hpp"
using namespace std;

int main()
{
    int n;
    double p1, p4, T1, T4, rho1, rho4, gamma;

    cout << "Low Pressure Region:\nP1 = ";
    cin >> p1;
    cout << "T1 = ";
    cin >> T1;
    cout << "High Pressure Region:\nP4 = ";
    cin >> p4;
    cout << "T4 = ";
    cin >> T4;

    vector<double> init = {p1, T1, p4, T4};
    shock compWave;
    expansionWaves expFan;
    
    string DIRNAME = "data";
    double dt, t, totalTime;
    double xl, xr, x_shock, x_diaphragm, dx;

    xl = -30000;
    xr = 30000;
    
    totalTime = 8;
    dt = 0.05;
    t = 0;

    compWave.initialConditions(init);

    gamma = compWave.gamma;
    rho1 = compWave.rho1;
    rho4 = compWave.rho4;
    // cout << compWave.p2 << "\n";
    // cout << compWave.a4 << " " << compWave.a2 << " " << compWave.up << "\n";

    expFan.a3 = compWave.a2;
    expFan.a4 = compWave.a4;
    expFan.u3 = compWave.up;
    expFan.u4 = 0.0;
    expFan.n = n;

    expFan.reflection();

    vector<waveProperties> waves(n+2);

    waves[0].p_behind = p4;
    waves[0].rho_behind = rho4;
    waves[0].speed = 0.0;
    waves[0].T_behind = T4;
    waves[0].pos = 0.0;

    for(int i = 1; i <= n; i++)
    {
        waves[i].p_behind = p4*pow(1 - (gamma-1)*expFan.slopes[i][0]/(2*expFan.slopes[0][1]), 2*gamma/(gamma-1));
        waves[i].rho_behind = rho4*pow(1 - (gamma-1)*expFan.slopes[i][0]/(2*expFan.slopes[0][1]), 2/(gamma-1));
        waves[i].speed = expFan.slopes[i][0] - expFan.slopes[i][1];
        waves[i].T_behind = T4*pow(1 - (gamma-1)*expFan.slopes[i][0]/(2*expFan.slopes[0][1]), 2);
        waves[i].pos = 0.0;
    }

    waves[n+1].p_behind = p1;
    waves[n+1].rho_behind = compWave.rho1;
    waves[n+1].speed = compWave.W;
    waves[n+1].T_behind = T1;
    waves[n+1].pos = 0.0;

    

    return 0;
}