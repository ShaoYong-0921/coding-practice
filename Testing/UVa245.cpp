#include <iostream>

using namespace std;

struct ListNode{
    string s;
    ListNode* next = nullptr;
    ListNode(string str) : s(str) {}
};

void insert(ListNode* head, string s){
    // cout << "s = " << s << "\n";
    ListNode* node = new ListNode(s);
    ListNode* ptr = head -> next;
    node -> next = ptr;
    head -> next = node;
}

void printS(ListNode* head, int n){
    ListNode* ptr = head;
    ListNode* last = ptr;
    while(n --) {
        last = ptr;
        ptr = ptr -> next;
    }
    cout << ptr -> s;
    last -> next = ptr -> next;
    ptr -> next = head -> next;
    head -> next = ptr;
}

bool atoz(char c){
    if( ('a' <= c && c <= 'z') || ( 'A' <= c && c <= 'Z') ) return true;
    else return false;
}

int main(){
    string s;
    ListNode* dummy = new ListNode("abc");
    while( getline(cin, s) && s != "0"){
        string str = "";
        int n = 0;
        bool last = false;
        for(int i=0; i<s.size(); i++){
            if (i == s.size() - 1) last = true;

            if ('0' <= s[i] && s[i] <= '9'){
                if ('0' <= s[i-1] && s[i-1] <= '9') 
                    n = n * 10 + (s[i] - '0');
                else n = s[i] - '0';
                if (last || s[i+1] < '0' || s[i+1] > '9'){
                    printS(dummy, n);
                    n = 0;
                }
            }

            else if ( atoz(s[i]) ){
                str += s[i];
                if (last || !atoz(s[i+1])){
                    cout << str;
                    insert(dummy, str);
                    str = "";
                }
            }
            else 
                cout << s[i];
        }
        cout << '\n';
    }
    // while(dummy){
    //     cout << dummy -> s << " ";
    //     dummy = dummy -> next;
    // }
}

