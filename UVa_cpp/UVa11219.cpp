#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    int kase = 0;
    while(t--){
        int d1, m1, y1, d2, m2, y2;
        // scanf("%d", &n);
        scanf("%2d/%2d/%4d", &d1, &m1, &y1);
        scanf("%2d/%2d/%4d", &d2, &m2, &y2);
      // cout << d2 << " " << m2 << " " << y2 << endl;
       int age;
       cout << "Case #" << ++kase << ": ";
       if (y1 < y2) { cout << "Invalid birth date\n"; continue; }
       else if (y1 == y2 && (m1 < m2 || (m1 == m2 && d1 < d2))){
            cout << "Invalid birth date\n"; 
            continue;
       }
       else {
            age = y1 - y2;
            if (m1 < m2 || (m1 == m2 && d1 < d2)) age --;
       }
       if (age > 130) cout << "Check birth date\n";
       else cout << age << '\n';
    }
}