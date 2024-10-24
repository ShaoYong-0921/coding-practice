#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

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

double path(point p1, point p2, sphere s){
    point p(p2.x - p1.x, p2.y - p1.y, p2.z - p2.z);
    point d(p.x - s.x, p.y - s.y, p.z - s.z);
    double A = (p.x * p.x) + (p.y * p.y) + (p.z * p.z);
    double B = 2 * ( d.x + d.y + d.z );
    double C = (d.x * d.x) + (d.y * d.y) + (d.z * d.z) - (s.r * s.r);

    double Discriminant = B * B - 4 * A * C;
    if (Discriminant < 0) return 0;
    double t1 = (B + sqrt(Discriminant)) / (2 * A);
    double t2 = (-B + sqrt(Discriminant)) / (2 * A);

    point start(p1.x + t1 * p.x,
                p1.y + t1 * p.y,
                p1.z + t1 * p.z);
    point end(  p2.x + t2 * p.x,
                p2.y + t2 * p.y,
                p2.z + t2 * p.z);
                
    return distance(start, end);

}

int main(){
    string city;
    while( cin >> city){
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
        cout << "p1 = " << p1.x << " " << p1.y << " " << p1.z << '\n';
        cout << "p2 = " << p2.x << " " << p2.y << " " << p2.z << '\n';

    }
}