#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int,int> pii;

bool cmp(const pii& a, const pii& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}


vector<int> solution(string s) {
    vector<int> answer;
 
    map<int,int> m;
    string tmp="";
    for(int i=1;i<s.length()-1;i++){
        if(s[i] != '{' && s[i] != '}' && s[i] != ','){
            tmp += s[i];
        }
        else if(s[i] == '}'){
            m[stoi(tmp)]++;
            tmp="";
        } else if(s[i] == ','){
            if(!tmp.empty()) {
                m[stoi(tmp)]++;
                tmp="";
            }
        }
    }
    
    vector<pii> v;
    for(auto& k:m){
        v.push_back({k.first,k.second});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto& k:v){
        answer.push_back(k.first);
    }
    return answer;
}
