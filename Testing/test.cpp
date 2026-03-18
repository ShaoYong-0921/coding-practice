#include <iostream>

using namespace std;

struct node{
    int idx = 0;
    string s = "*";
    node* nxt = nullptr;
    node* lst = nullptr;
};

void getc(string s, node* head){
    string output = "";
    node* ptr = head;
    for(int i=7; i<s.size(); ++i){
        output += s[i];
        if (s[i] == ' ' || i == s.size()-1){
            node* n = new node;
            n -> s = output;
            n -> idx = i - 7 - output.size() + 1;
            n -> lst = ptr;

            ptr -> nxt = n;
            ptr = ptr -> nxt;
            output = "";
        }
    }
}

string lower(string s){
    string str = s;
    for(int i=0; i<str.size(); ++i) 
        if('A' <= str[i] && str[i] <= 'Z') 
            str[i] += 'a' - 'A';
    return str;
}

int main(){
    string s1, s2;
    while(getline(cin, s1) && getline(cin, s2)){
        s1 = lower(s1);
        s2 = lower(s2);
        node* head1 = new node;
        node* head2 = new node;

        // cout << "s1 = " << s1 << endl;
        // cout << "s2 = " << s2 << endl;
        getc(s1, head1);
        getc(s2, head2);
        node *ptr1 = head1 -> nxt;
        node *ptr2 = head2 -> nxt;
        int sum = 0;
        while(ptr1 || ptr2){
            if(!ptr1 -> nxt || !ptr2 -> nxt){
                if(!ptr1) cout << "pos " << ptr1 -> idx << " deleted " << (ptr1 -> s).size() << " chars " << ptr1 -> s << endl;
                else if(!ptr2) cout << "pos " << ptr1 -> idx << " inserted " << (ptr2 -> s).size() << " chars " << ptr2 -> s << endl;
                else cout << "pos " << ptr2 -> idx << " changed " << (ptr2 -> s).size() << " chars " << ptr2 -> s << " to " << ptr1 -> s<< endl;
                break;
            }
            if(ptr1 -> s != ptr2 -> s){
                //delete
                // cout << ptr1 -> s << endl;
                // cout << ptr2 -> s << endl;
                // cout << endl;
                if (ptr1 -> s == ptr2 -> nxt -> s){
                    int k = (ptr2 -> s).size();
                    cout << "pos " << ptr2 -> idx << " deleted " << k << " chars " << ptr2 -> s << endl;
                    ptr2 = ptr2 -> nxt;
                }
                if (ptr2 -> s == ptr1 -> nxt -> s){
                    int k = (ptr1 -> s).size();
                    cout << "pos " << (ptr2 -> idx) << " inserted " << k << " chars " << ptr1 -> s << endl;
                    ptr1 = ptr1 -> nxt;
                
                }
            }
            ptr1 = ptr1 -> nxt;
            ptr2 = ptr2 -> nxt;
        }

    }
}