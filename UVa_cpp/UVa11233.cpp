#include <iostream>

using namespace std;

string str[100], plural[100];

int main(){
    int l, n, i, j, k;
    string s;
    cin >> l >> n;
    for(i=0; i<l; i++)
        cin >> str[i] >> plural[i];
    for(i=0; i<n; i++){
        cin >> s;
        string tail = "  ";
        bool irregular = false, flag = true;
        int index;
        for(j=0; j<l; j++){
            if(s == str[j]){
                index = j;
                irregular = true;
                break;
            }
        }
        int n = s.size();
        //cout << "size = " << n << endl;
        if (n < 2) {
            flag = false;
            tail = " " + s;
        }
        for(j=0; j<2 && flag; j++)
            tail[j] = s[n - 2 + j];
        // cout << "end = " << tail << endl;
        if (irregular)
            cout << plural[index] << "\n";
        else if(tail[1] == 'y' && tail[0] != 'a' &&
                tail[0] != 'e' && tail[0] != 'i' &&
                tail[0] != 'o' && tail[0] != 'u' ){
            for(j=0; j<n-1; j++)
                cout << s[j];
            cout << "ies\n";
        }
        else if(tail[1] == 'o' || tail[1] == 's' || tail[1] == 'x' || 
                tail == "ch" || tail == "sh" ){
            cout << s << "es\n";
        }
        else
            cout << s << "s\n";
            

    }
    
}