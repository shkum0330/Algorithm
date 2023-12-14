#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

struct Trie{
    map<string,Trie*> m;
    void insert(vector<string> v,int idx){
        if(idx==v.size()) return;
        if(m.find(v[idx])==m.end()){
            Trie* trie=new Trie();
            m[v[idx]]=trie;
        }
        m[v[idx]]->insert(v,idx+1);
    }
    void dfs(int depth){
        for(auto& k:m){
            for (int i = 0; i < depth; ++i) {
                cout << "--";
            }
                cout<<k.first<<'\n';
                k.second->dfs(depth+1);
                delete k.second;

        }
    }
};

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Trie *root=new Trie();
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int k; cin>>k;
        vector<string> v;
        for (int j = 0; j < k; ++j) {
            string s; cin>>s;
            v.push_back(s);
        }
        root->insert(v,0);
    }
    root->dfs(0);
    delete root;
}
