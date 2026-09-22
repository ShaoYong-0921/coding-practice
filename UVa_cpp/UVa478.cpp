#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

char type[100];

double cross(double x1, double y1, double x2, double y2, double px, double py){
    return (x2 - x1)*(py - y1) - (y2 - y1)*(px - x1);
}

int main(){
    vector<vector<double>> point;
    int n = 0; string s;
    while(getline(cin, s) && s != "*"){
        stringstream ss(s);
        char t; double d;
        ss >> t; type[n] = t;
        // cout << t << endl;
        vector<double> p;
        while(ss >> d) p.push_back(d); 
        point.push_back(p);
        ++ n;
    }
    double x, y; int idx = 0;
    while(cin >> x >> y && !(x == 9999.9 && y == 9999.9)){
        bool in = false;
        //cout << x << " | " << y << endl;
        for(int i=0; i<n; ++i){
            if (type[i] == 'c'){
                double dx = abs(x - point[i][0]);
                double dy = abs(y - point[i][1]);
                // double d = sqrt(dx * dx + dy * dy); cout << "d = " << d << endl;
                if (sqrt(dx * dx + dy * dy) < point[i][2]){
                    cout << "Point " << idx + 1 << " is contained in figure " << i + 1 << endl;
                    in = true;
                }
            }
            else if (type[i] == 'r'){
                if (point[i][0] < x && x < point[i][2] && 
                        point[i][3] < y && y < point[i][1] ){
                     cout << "Point " << idx + 1 << " is contained in figure " << i + 1 << endl;
                     in = true;
                    
                }
            }
            else if (type[i] == 't'){
                double d1 = cross(point[i][0], point[i][1], point[i][2], point[i][3], x, y);
                double d2 = cross(point[i][2], point[i][3], point[i][4], point[i][5], x, y);
                double d3 = cross(point[i][4], point[i][5], point[i][0], point[i][1], x, y);
                // cout << "d1 = " << d1 << " d2 = " << " d3 = " << d3 << endl;
                if ((d1 < 0 && d2 < 0 && d3 < 0) || (d1 > 0 && d2 > 0 && d3 >0)) {
                    cout << "Point " << idx + 1 << " is contained in figure " << i + 1 << endl;
                    in = true;
                }
            }
        }
        if (!in)  cout << "Point " << idx + 1 << " is not contained in any figure" << endl;
        idx ++;
    }
}