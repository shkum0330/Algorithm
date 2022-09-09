#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s;
    bool hasZero=true;
    int zeroIndex;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0') {
            zeroIndex=i;
            break;
        }
        if(i==s.length()-1) hasZero= false;
    }
    if(hasZero== false){
        cout<<-1<<'\n';
        return 0;
    }
    swap(s[zeroIndex],s[s.length()-1]);

    vector<int> v;
    for(int i=0;i<s.length()-1;i++){
        v.push_back(s[i]-'0');
    }

    sort(v.begin(),v.end(),greater<>());

    long long sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    if(sum % 3 != 0){
        cout<<-1<<'\n';
        return 0;
    }
    for(int i=0;i<v.size();i++) cout<<v[i];
    cout<<0<<'\n';
}
