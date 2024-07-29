#include <iostream>

using namespace std;

struct ListNode{
    string s;
    ListNode* next = nullptr;
    ListNode(string str) : s(str) {}
};

int main(){
    string s;
    ListNode* dummy = new ListNode("abc");
    ListNode* tail = dummy;
    cout << "s = " << dummy -> s << "\n";
    while( getline(cin, s) && s != "0"){
        bool flag = true;
        string str = "";
        int n = 0;
        for(int i=0; i<s.size(); i++){
            if ( ( 'a' <= s[i] && s[i] <= 'z') || 
                 ( 'A' <= s[i] && s[i] <= 'Z') ){
                str += s[i];
            }
            else if ('0' <= s[i] && s[i] <= '9'){
                if ('0' <= s[i-1] && s[i-1] <= '9') n = n * 10 + (s[i] - '0');
                else n = s[i] - '0';
                cout << "n = " << n << "\n";
            }
            else {
                if (str == "") continue;
                if (n > 0) {
                    ListNode* ptr = dummy;
                    for(int j=0; j<n; j++){
                        ptr = ptr -> next;   
                    }
                    cout << "ptr = " << ptr -> s << "\n";
                }
                // cout << "str = " << str << "\n";
                tail -> next = new ListNode(str);
                tail = tail -> next;
                str = "";
            }
        }
        cout << s << '\n';
    }
    while(dummy){
        cout << dummy -> s << " ";
        dummy = dummy -> next;
    }
}