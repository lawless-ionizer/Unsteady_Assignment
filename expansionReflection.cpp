#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    double u3, u4, a3, a4, u, a;
    u4 = 0.0;
    u3 = 281.826;
    a4 = 346.029;
    a3 = 407.837;
    double gamma = 1.4;

    int n;
    cin >> n;

    vector<vector<double>> slopes;
    u = u4;
    a = a4;
    for(int i = 0; i < n; i++)
    {
        slopes.push_back({u,a});
        u = (u3 - u4)/(n-1)*1.0*(i+1);
        a = a4 + (a3 - a4)/(n-1)*1.0*(i+1);
    }

    vector<vector<vector<double>>> intersections;
    vector<vector<double>> characteristic(n, vector<double>(2,0));
    for(int i = n; i > 0; i--)
    {
        intersections.push_back(characteristic);
        characteristic.pop_back();
    }
    intersections[0] = slopes;

    for(int i = 1; i < n; i++)
    {
        intersections[i][0][1] = intersections[i-1][1][1] - (gamma-1)*intersections[i-1][1][0]/2.0;
        for(int j = 1; j < n - i; j++)
        {
            intersections[i][j][0] = 0.5*(intersections[i][j-1][0] + intersections[i-1][j+1][0] + 2.0*(intersections[i][j-1][1] - intersections[i-1][j+1][1])/(gamma-1));
            intersections[i][j][1] = 0.25*(gamma-1)*(intersections[i][j-1][0] - intersections[i-1][j+1][0] + 2.0*(intersections[i][j-1][1] + intersections[i-1][j+1][1])/(gamma-1));
        }
    }

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 0; j < n - i; j++)
            cout << fixed << setprecision(2) << intersections[i][j][0] << " ";
        
        cout << "\n";
        for(int j = 0; j < n - i; j++)
            cout << fixed << setprecision(2) << intersections[i][j][1] << " ";

        cout << "\n\n";
    }

    return 0;
}