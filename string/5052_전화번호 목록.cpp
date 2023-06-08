#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int t;

struct Trie{
    map<char,Trie*> m;
    bool finish;
    void insert(vector<char>& v,int idx){
        if(idx==v.size()) {
            finish=true;
            return;
        }
        if(m.find(v[idx])==m.end()){
            Trie* trie=new Trie();
            m[v[idx]]=trie;
        }
        m[v[idx]]->insert(v,idx+1);
    }

    bool find(vector<char>& v,int idx){
        if(idx==v.size()) return false;
        if(finish) return true;
        if(m[v[idx]] == NULL) return false;
        return  m[v[idx]]->find(v,idx+1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while (t--) {
        bool flag=true;
        Trie* root=new Trie();
        int n; cin>>n;
        vector<char> pv[n];
        for (int i = 0; i < n; ++i) {
            string s; cin>>s;
            vector<char> v;
            for (int j = 0; j < s.size(); ++j) {
                v.push_back(s[j]);
            }
            pv[i]=v;
            root->insert(v,0);
        }

        for (int i = 0; i < n; ++i) {
            if(root->find(pv[i],0)){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}