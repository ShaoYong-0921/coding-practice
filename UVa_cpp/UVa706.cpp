#include <iostream>

using namespace std;

string num[10]= { "abcefg", "cf", "acdeg", "acdfg", "bcdf", "abdfg", "abdefg", "acf", "abcdefg", "abcdfg"};


int main(){

    int s, n;
    string numbers;

    while(cin >> s >> numbers){
        if (s == 0 && numbers == "0") break;

        auto find = [&](char c) -> bool {
            for(auto i : num[n]) if (i == c) return true; 
            return false;
        };

        auto output_h = [&](char c) -> void {
            bool f = true;
            for(int j=0; j<numbers.size(); ++j){
                if (!f) cout << " "; f = false;

                n = numbers[j] - '0';
                cout << " ";
                for(int i=0; i<s; ++i){
                    if (find(c)) cout << "-";
                    else cout << " ";
                }
                cout << " ";
            }
            cout << '\n';
        };

        auto output_m = [&](char c1, char c2) -> void {
            bool f = true; 
            for(int j=0; j<numbers.size(); ++j){
                if (!f) cout << " "; f = false;
                n = numbers[j] - '0';

                if (find(c1)) cout << "|";
                else cout << " ";
                for(int j=0; j<s; ++j) cout << " ";
                if (find(c2)) cout << "|";
                else cout << " ";

            }
            cout << '\n';
        };

        output_h('a');
        for(int i=0; i<s; ++i) output_m('b', 'c');
        output_h('d');
        for(int i=0; i<s; ++i) output_m('e', 'f');
        output_h('g');
        cout << '\n';
    }


}