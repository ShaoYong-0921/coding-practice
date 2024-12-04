#include <iostream>
#include <string>

using namespace std;

struct NHC{
    string target[105];
    int t1[105], t2[105], idx = 0;
};

NHC table[10005];

int main(){
    string source, time, duration, target;
    int n;
    cin >> n;
    cout << "CALL FORWARDING OUTPUT\n";
    for(int i=1; i<=n; i++){
        
        cout << "SYSTEM " << i << '\n';
        while( cin >> source && source != "0000"){
            cin >> time >> duration >> target;
            int s = stoi(source);
            int idx = table[s].idx;
            table[s].target[idx] = target;
            table[s].t1[idx] = stoi(time);
            table[s].t2[idx] = stoi(time) + stoi(duration);
            table[s].idx ++;
        }
        while( cin >> time && time != "9000"){
            string exten;
            cin >> exten;
            // cout << "At " << time << " CALL TO " << exten << "\n";

            int t = stoi(time), num = stoi(exten);
            string now = "0";
            while(true){
                if (now == exten) break;
                bool next = false;
                // cout << "now = " << now << '\n';
                int idx = table[num].idx;
                for(int j=0; j<idx; j++){
                    if(table[num].t1[j] <= t && t <= table[num].t2[j]){
                        now = table[num].target[j];
                        num = stoi(now);
                        next = true;
                        // cout << "next = " << now << '\n';
                        break;
                    }
                }
                if (next) continue;
                else break;
            }
            if (now == exten) now = "9999";
            if (now == "0") now = exten;
            cout << "AT " << time << " CALL TO " << exten << " RINGS " << now << '\n';

        }
        for(int j=0; j<10005; j++){
            table[j].idx = 0;
        }

    }
    cout << "END OF OUTPUT\n";
}