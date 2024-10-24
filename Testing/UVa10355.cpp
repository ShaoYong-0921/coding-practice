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

void print(point p){
    cout << "(" << p.x << "," << p.y << "," << p.z << ")\n";
}
double path(point p1, point p2, sphere s){
    point d(p2.x - p1.x, p2.y - p1.y, p2.z - p2.z);
    point f(p1.x - s.x, p1.y - s.y, p1.z - s.z);

    cout << "d :";
    print(d);
    cout << "f :";
    print(f);

    double A = (d.x * d.x) + (d.y * d.y) + (d.z * d.z);
    double B = 2 * ( f.x * d.x + f.y * d.y + f.z * d.z);
    double C = (f.x * f.x) + (f.y * f.y) + (f.z * f.z) - (s.r * s.r);
    cout << "A = " << A << " B = " << B << " C = " << C << "\n";
    double Discriminant = B * B - 4 * A * C;
    cout << "Discriminant = " << Discriminant << "\n";

    if (Discriminant < 0) return 0;
    double t1 = (B + sqrt(Discriminant)) / (2 * A);
    double t2 = (-B + sqrt(Discriminant)) / (2 * A);
    cout << "t1 = " << t1 << " t2 = " << t2 << "\n";

    point start(p1.x + t1 * d.x,
                p1.y + t1 * d.y,
                p1.z + t1 * d.z);
    point end(  p1.x + t2 * d.x,
                p1.y + t2 * d.y,
                p1.z + t2 * d.z);
    cout << "start = ";
    print(start);
    cout << "end = ";
    print(end);
    cout << '\n';                
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
        for(int i=0; i<pollute.size(); i++){
            double dis = path(p1, p2, pollute[i]);
            cout << "distance = " << dis << '\n';
        }
        cout << "p1 = " << p1.x << " " << p1.y << " " << p1.z << '\n';
        cout << "p2 = " << p2.x << " " << p2.y << " " << p2.z << '\n';

    }
}