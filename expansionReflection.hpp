#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

class expansionWaves
{
    public:
    double u3, u4, a3, a4, u, a;
    double gamma = 1.4;
    int n;

    vector<vector<double>> slopes;

    vector<vector<vector<double>>> intersections;
    void reflection();
};