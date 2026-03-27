#include <iostream>

using namespace std;

int digit1[110];
int digit2[110];
int sum[110];

int idx;
void print(){
    cout << "print:";
    for(int i=0; i<idx+1; ++i){
        cout << sum[i];
    }
    cout << endl;
}

int main(){
    string s1, s2, str;
    bool first = true;
    while(getline(cin, s1)){
        getline(cin, s2);
        getline(cin, str);
        if (!first) cout << '\n';
        first = false;

        for(int i=0; i<110; ++i){
            digit1[i] = 0;
            digit2[i] = 0;
            sum[i] = 0;
        }
        for(int i=0; i<s1.size(); i++) digit1[i] = (s1[s1.size() - 1 - i] - '0');
        for(int i=0; i<s2.size(); i++) digit2[i] = (s2[s2.size() - 1 - i] - '0');

        idx = (s1.size() > s2.size()) ? s1.size() : s2.size();
        // cout << "sum:";
        for(int i=0; i<105; ++i){
            sum[i] = digit1[i] + digit2[i];
            // cout << sum[i];
        }
        // cout << endl;
        while(1){
            for(int i=2; i<105; ++i){
                if (sum[i] >= 2){
                    sum[i+1] ++;
                    sum[i-2] ++;
                    sum[i] -= 2;
                }
            }
            // print();
            for(int i=0; i<105; ++i){
                if (sum[i] >= 1 && sum[i+1] >= 1){
                    sum[i] --;
                    sum[i+1] --;
                    sum[i+2] ++;
                }
            }

            if (sum[1] >= 2){
                sum[1] -= 2;
                sum[0] ++;
                sum[2] ++;
            }
            if (sum[0] >= 2){
                sum[0] -= 2;
                sum[1] ++;
            }

            bool nxt = false;
            for(int i=0; i<105; ++i){
                if (sum[i] >= 1 && sum[i+1] >= 1) nxt = true;
                if (sum[i] >= 2) nxt = true;
            }
            // cout << "nxt:";
            // print();
            if (!nxt) break;

        }
        bool p = false;
        for(int i=100; i>=0; --i){
            if(sum[i]) p = true;
            if(p) cout << sum[i];
        }
        if (!p) cout << '0';
        cout << endl;
    }
}