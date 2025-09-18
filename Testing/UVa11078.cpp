#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int score[100005];
int indx[10005];
bool used[150005];

int main(){
    int t, n;
    cin >> t;
    while(t --){
        for(int i=0; i<150005; i++) used[i] = false;
        cin >> n;
        int num, idx=0;
        for(int i=0; i<n; i++){
            cin >> num;
            if (!used[num]){
                score[idx] = num;
                indx[num] = i;
                used[num] = true;
                idx ++;
            }
        }
        sort(score, score + idx);
        for(int i=0; i<idx; i++)
            cout << "score[" << i << "] = " << score[i] << " idx:" << indx[score[i]] << '\n';

        // score[i] - score[i+j] j = 1, 2, 3 ... n-1
        int maxium = -(1 << 31);
        bool notf = true;
        for(int i=0; i<idx, notf; i++){
            for(int j=idx-1; j>i, notf; j--){
                if(indx[score[i]] < indx[score[j]]){
                    cout << indx[score[i]] << ":" << indx[score[j]] << '\n';
                    maxium = score[i] - score[j];
                    notf = false;
                }
            }
        }

        cout << maxium << "\n";
            // 20 0 30 0 40 35 max = 20
            // 20 45 0 20 0 max = 45 

    }

    // for(int i=0; i<n; i++)
    //     cout << "score[" << i <<  "] = " << score[i] << "\n";
}