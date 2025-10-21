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
    };

    private:
    void initialConditions(vector<double> initialState);
    void stepCalculate();
    void storeinFile();
    void newtonRaphson();
    double f(double x);
    double f_(double x);

    double p1, p2, p4;
    double gamma, R;
    double T1, T4;
    double N, D1, D2, r, k, k_;

};
