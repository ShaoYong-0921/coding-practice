#include <iostream>

using namespace std;

struct jar{
    int v;
    int t;
};

jar jars[3005];

int sumcap(int a, int b){
    int sum = 0;
    for(int i=a; i<=b; i++)
        sum += jars[i].v;
    // cout << "i = " << a << " j = " << b << '\n';
    // cout << "sum = " << sum << '\n';
    return sum;
}

double caltemp(int a, int b){
    double vt = 0, v = 0;
    for(int i=a; i<=b; i++){
        vt += jars[i].v * jars[i].t;
        v += jars[i].v;
    }
    // cout << "temperture: " << vt / v << '\n';
    return vt / v;
}

int main(){
    int capacity, tartemp;
    int problems, n;
    cin >> problems;
    while(problems --){
        cin >> capacity >> tartemp;
        cin >> n;
        // cout << "num:" << n<< '\n';
        for(int i=0; i<n; i++){
            cin >> jars[i].v >> jars[i].t;
        }
        double minium = 0xFFFFFFFF;
        int minium_i, minium_j;
        bool findMin = false;

        for(int i=0, j=0; i<n; i++){
            for(int j=i; j<n; j++){
                int sum = sumcap(i,j);
                if (capacity/2 <= sum && sum <= capacity){
                    // cout << "curcap: " << sum << " range:" << i << "~" << j <<'\n';
                    double temp = caltemp(i,j);
                    double num = abs(tartemp - temp);

                    if (num <= 5){
                        findMin = true;
                        if (num < minium) {
                            minium = num;
                            minium_i = i;
                            minium_j = j;
                        }

                    }
                }

            }

        }
        if (findMin)
            cout << minium_i << " " << minium_j << '\n';
        else
            cout << "Not possible\n";
    }
}