#include <bits/stdc++.h>
using namespace std;

// 비트마스킹으로도 풀 수 있다.
int m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    set<int> s;
    cin>>m;
    while(m--){
        string cal; int num;
        cin>>cal;
        if(cal=="add") {
            cin>>num;
            s.insert(num);
        }
        else if(cal=="remove"){
            cin>>num;
            s.erase(num);
        }
        else if(cal=="check") {
            cin>>num;
            if(s.find(num) != s.end()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if(cal=="toggle"){
            cin>>num;
            if(s.find(num) != s.end()) s.erase(num);
            else s.insert(num);
        }
        else if(cal=="all"){
            for(int i=1;i<=20;i++) s.insert(i);
        }
        else if(cal=="empty") s.clear();
    }
}