#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int cnt;
    string s;
    set<string> arr;
    while(getline(cin, s)){
        string word = "";
        for(auto i: s){
            if ('a' <= i && i <= 'z')
                word += i;
            else if ('A' <= i && i <= 'Z')
                word += i + ('a' - 'A');
            else{
                if (word != "") arr.insert(word);
                word = "";
            }
            // cout << "word: "<< word;
        }
        if (word != "") arr.insert(word);
    }
    for(auto i: arr)
        cout << i << '\n';
}