#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct waveProperties
{
    double p_behind;
    double T_behind;
    double rho_behind;
    double speed;
    double speed_behind;
};

class shock
{
    public:
    shock()
    {
        R = 287;
        gamma = 1.4;
    };
    void initialConditions(vector<double> initialState);
    void shockReflection();

    double p1, p2, p4, p5;              // Pressures
    double rho1, rho2, rho4, rho5;      // Densities
    double gamma, R;                    // Gas Constants
    double T1, T2, T4, T5;              // Temperatures
    double a1, a2, a4, a5;              // Sonic Velocities
    double W, Wr, up;                   // Velocities
    double Ms, Mr;                      // Mach numbers
    waveProperties compWave;

    private:
    void newtonRaphson();
    void propertyCalculations();
};
