#include <bits/stdc++.h>
using namespace std;

vector<int> getPi(string p){
    int m=p.length();
    int j=0;
    vector<int> pi;
    for (int i = 0; i < m; i++) {
        pi.push_back(0);
    }
    for (int i = 1; i < m; i++) {
        while (j>0 && p[i] != p[j]){
            j=pi[j-1];
        }
        if(p[i]==p[j]){
            j++;
            pi[i]=j;
        }
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    string s; cin>>n>>s;
    vector<int> pi= getPi(s);
    cout<<s.size()-pi[s.size()-1]<<'\n';
}
