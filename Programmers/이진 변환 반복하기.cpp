#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt=0;
    int zero=0;
    while(true){
        if(s=="1") break;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zero++;
                s.erase(i,1);
                i--;
            }
        }
        int num=s.size();
        s="";
        while(num!=0){
            if(num%2==0) s='0'+s;
            else s='1'+s;
            num/=2;
        }
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    cout<<s;
    return answer;
}
