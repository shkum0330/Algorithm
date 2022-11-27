#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
        if(!(s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9' || s[i]=='-'|| s[i]=='_'|| s[i]=='.')){
            s.erase(i,1); i--;
        }
    }
     for(int i=0;i<s.size()-1;i++){
         if(s[i]=='.' && s[i+1]=='.') {
              s.erase(i,1); i--;
         }
     }
    if(s[0]=='.')  s.erase(0,1);
    if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
    if(s.empty()) s+='a';
    if(s.size()>15) {
        s.erase(s.begin()+15,s.end());
        if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
    }
     if(s.size()<3) {
      char tmp=s[s.size()-1];
         while(s.size()<3){
             s += tmp;
         }
    }
    cout<<s<<'\n';
    return s;
}
