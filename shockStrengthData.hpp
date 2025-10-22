#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
using namespace std;

typedef struct data{
    double r;
    double x;
};

class shock
{
    public:
    shock()
    {
        R = 287;
        gamma = 1.4;
    };

    private:
    void initialConditions(vector<double> initialState);
    void newtonRaphson();
    void shockReflection();

    double p1, p2, p4, p5;              // Pressures
    double rho1, rho2, rho4, rho5;      // Densities
    double gamma, R;                    // Gas Constants
    double T1, T2, T4, T5;              // Temperatures
    double a1, a2, a4, a5;              // Sonic Velocities
    double W, Wr, up;                   // Velocities

};
