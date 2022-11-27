#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    int idx=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            idx=0; continue;
        }
        if(idx%2==0 && s[i]>='a' && s[i]<='z') {
            s[i] -= 32; idx++;
        }
        else if(idx%2!=0 && s[i]>='A' && s[i]<='Z') {
            s[i] += 32; idx++;
        } else idx++;
    }
    return s;
}
