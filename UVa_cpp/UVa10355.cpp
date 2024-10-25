#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

struct point{
    double x, y, z;
    point(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {} 
};

struct sphere{
    double x, y, z, r;
    sphere(double x = 0, double y = 0, double z = 0, double r = 0): x(x), y(y), z(z), r(r) {}
};

double distance(point p1, point p2){
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + 
                (p2.y - p1.y) * (p2.y - p1.y) + 
                (p2.z - p1.z) * (p2.z - p1.z));  
}

string print(point p){
    cout << "(" << p.x << "," << p.y << "," << p.z << ")";
    return "\n";
}

double path(point p1, point p2, sphere s){
    point d(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
    point f(p1.x - s.x, p1.y - s.y, p1.z - s.z);

    // cout << "d : " << print(d);
    // cout << "f : " << print(f);

    double A = (d.x * d.x) + (d.y * d.y) + (d.z * d.z);
    double B = 2 * ( f.x * d.x + f.y * d.y + f.z * d.z);
    double C = (f.x * f.x) + (f.y * f.y) + (f.z * f.z) - (s.r * s.r);
    // cout << "A = " << A << " B = " << B << " C = " << C << "\n";
    double Discriminant = B * B - 4 * A * C;
    // cout << "Discriminant = " << Discriminant << "\n";

    if (Discriminant < 0) return 0;
    double t1 = (-B + sqrt(Discriminant)) / (2 * A);
    double t2 = (-B - sqrt(Discriminant)) / (2 * A);
    if(t1 > t2) swap(t1, t2);

    if (t1 > 1 || t2 < 0) return 0;
    if(t1 < 0) t1 = 0;
    if(t2 > 1) t2 = 1;
    // cout << "t1 = " << t1 << " t2 = " << t2 << "\n";

    point start(p1.x + t1 * d.x,
                p1.y + t1 * d.y,
                p1.z + t1 * d.z);
    point end(  p1.x + t2 * d.x,
                p1.y + t2 * d.y,
                p1.z + t2 * d.z);

    // cout << "start = " << print(start);
    // cout << "end = " << print(end);
    return distance(start, end);

}

int main(){
    string city;
    while( cin >> city ){
        cout << city << '\n';
        point p1, p2;
        vector<sphere> pollute;
        cin >> p1.x >> p1.y >> p1.z >> p2.x >> p2.y >> p2.z;
        int n;
        cin >> n;
        while (n --){
            sphere p;
            cin >> p.x >> p.y >> p.z >> p.r;
            pollute.push_back(p);
        }

        double total = 0;
        for(int i=0; i<pollute.size(); i++){
            total += path(p1, p2, pollute[i]);
        }
        // cout << "line = " << distance(p1, p2) << '\n';
        // cout << "total = " << total << "\n";
        double ans = total / distance(p1, p2) * 100;
        cout << fixed << setprecision(2) << ans << "\n";
    }
}