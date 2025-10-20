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
    shock();

    private:
    void initialConditions();
    void stepCalculate();
    void storeinFile();

};
