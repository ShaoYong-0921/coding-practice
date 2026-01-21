#include <iostream>

using namespace std;

char rev[150];


int main(){
    // cout << "0 " << (int)('a') << endl;
    for(int i='0'; i<'z'; i++){
        rev[i] = '#';
    }

    rev['A'] = 'A'; rev['E'] = '3'; rev['H'] = 'H';
    rev['I'] = 'I'; rev['J'] = 'L'; rev['L'] = 'J';
    rev['M'] = 'M'; rev['O'] = 'O'; rev['S'] = '2';
    rev['T'] = 'T'; rev['U'] = 'U'; rev['V'] = 'V';
    rev['W'] = 'W'; rev['X'] = 'X'; rev['Y'] = 'Y';
    rev['Z'] = '5'; rev['1'] = '1'; rev['2'] = 'S';
    rev['3'] = 'E'; rev['5'] = 'Z'; rev['8'] = '8';
    
    string s;
    while(cin >> s){
        string r;
        for(int i=s.size() - 1; i>=0; --i) r += s[i];
        
        // cout << r << "\n";
        bool pal = true;
        bool mir = true;
        for(int i=0; i<s.size(); ++i){
            if (s[i] != r[i]) pal = false; 
            if (rev[s[i]] != r[i]) mir = false;
        }
        if (pal && mir) {
            cout << s << " -- is a mirrored palindrome.\n";
        }
        else if (pal) {
            cout << s << " -- is a regular palindrome.\n";
        }
        else if (mir) {
            cout << s << " -- is a mirrored string.\n";
        }
        else {
            cout << s << " -- is not a palindrome.\n";
        }
        cout << endl;
    }

}