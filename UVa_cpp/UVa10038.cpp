#include <iostream>
#include <map>

using namespace std;

int nums[3005];

int main(){
    int n;
    while( cin >> n ){
        map<int, bool> mp;
        bool isJumper = true;
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }
        for(int i=0; i<n-1; i++){
            int num1 = nums[i];
            int num2 = nums[i+1];
            if (mp[abs(num1 - num2)] == true){
                isJumper = false;
                break;
            }
            mp[abs(num1 - num2)] = true; 
        }
        for(int i=1; i<n; i++)
            if ( mp[i] == false ) isJumper = false;
        
        if (isJumper) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
}