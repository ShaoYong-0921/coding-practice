#include <iostream>
#include <climits>

using namespace std;

/*
  a
b   c   
  d
e   f
  g
*/

string lcd[15] = {
  "abcefg", "cf", "acdeg", "acdfg", "bcdf",
  "abdfg", "abdefg", "acf", "abcdefg", "abcdfg"
};


bool find(char c, int n){
  // cout << "lcd = " << lcd[n] << endl;
  for(auto i: lcd[n]){
    // cout << "i = " << i << endl;
    if (i == c) return true;
  }
  return false;
}

int main(){
    int s;
    string n;
    while( cin >> s >> n ){
      if (s == 0 && n == "0") break;
      string output = "";
      bool f = true;
      // head 
      for(auto i : n){
        int num = i - '0';
        if (!f) output += " ";
        f = false;

        if (find('a', num)){
          output += " ";
          for(int j=0; j<s; ++j) output += "-";  
          output += " ";
        }
        else
          for(int j=0; j<s+2; ++j) output += " ";
        
      }
      cout << output << endl;
      

      // body
      output = "";
      for(int j=0; j<s; ++j){
        f = true;
        for(auto i : n){
          int num = i - '0';
          if (!f) output += " ";
          f = false;

          if (find('b', num)) output += "|";
          else output += " ";
          for(int k=0; k<s; ++k) output += " ";
          if (find('c', num)) output += "|";
          else output += " ";
  
        }
        output += '\n';
      }
      cout << output ;

      // middle
      output = "", f = true;
      for(auto i : n){
        int num = i - '0';
        if (!f) output += " ";
        f = false;

        if (find('d', num)){
          output += " ";
          for(int j=0; j<s; ++j) output += "-";  
          output += " ";
        }
        else
          for(int j=0; j<s+2; ++j) output += " ";
        
      }
      cout << output << endl;

      // body
      output = "";
      for(int j=0; j<s; ++j){
        f = true;
        for(auto i : n){
          int num = i - '0';
          if (!f) output += " ";
          f = false;
          
          if (find('e', num)) output += "|";
          else output += " ";
          for(int k=0; k<s; ++k) output += " ";
          if (find('f', num)) output += "|";
          else output += " ";
  
        }
        output += '\n';
      }
      cout << output ;

      // bottom
      output = "", f = true;
      for(auto i : n){
        int num = i - '0';
        if (!f) output += " ";
        f = false;

        if (find('g', num)){
          output += " ";
          for(int j=0; j<s; ++j) output += "-";  
          output += " ";
        }
        else
          for(int j=0; j<s+2; ++j) output += " ";
        
      }
      cout << output << endl << endl;

    }
}