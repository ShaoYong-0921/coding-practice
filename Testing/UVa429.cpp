#include <iostream>
#include <string>

using namespace std;

string dict[1000];
bool edge[1000][1000];
struct map{
    string s;
    int n;
}

int main(){
    int T, i, j, k;
    string s;
    cin >> T;
    for(int i=0; i<T; i++){
        while(cin >> s && s != "*"){
            if (s == "") continue;
            cout << "[" << s << "]\n";
        }
        getline(cin, s);

        cout << "get out of loop 1\n"; 
        while(getline(cin, s)){
            if (s == "") break;
            string s1, s2;
            bool change = false;
            char c;
            for(j=0; j<s.size(); j++){
                c = s[j];
                if (c == ' '){
                    change = true;
                    continue;
                }
                if (!change) 
                    s1 += c;
                else 
                    s2 += c;
            }
            cout << "s1 = " << s1 << "\n";
            cout << "s2 = " << s2 << "\n";
        }
        cout << "get out of loop 2\n";
    }
}