#include <bits/stdc++.h>
using namespace std;

#define INF 1999999999
int n,m,r;
vector<int> e[100001];
int res[100001];
bool visited[100001];
int cnt=0;

void dfs(int v){
    cnt++;
    res[v]=cnt;
    visited[v]= true;
    for(int i=0;i<e[v].size();i++){
        if(e[v][i]!=0 && !visited[e[v][i]]){
            dfs(e[v][i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>r;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end());
    }
    dfs(r);
    for(int i=1;i<=n;i++) cout<<res[i]<<'\n';
}