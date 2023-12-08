#include <bits/stdc++.h>
using namespace std;

int n,m,r;
bool visited[200001];
vector<int> e[100001];
int depth;
int res[100001];

void dfs(int vertex){
    res[vertex]=depth;
    visited[vertex]= true;
    for(int i=0;i<e[vertex].size();i++){
        if(e[vertex][i] && !visited[e[vertex][i]]){
            depth++;
            dfs(e[vertex][i]);
            depth--;
        }
    }
}

int main(){
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
    for(int i=1;i<=n;i++) res[i]=-1;
    dfs(r);

    for(int i=1;i<=n;i++) cout<<res[i]<<'\n';
}