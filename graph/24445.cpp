#include <bits/stdc++.h>
using namespace std;

#define INF 1999999999
int n,m,r;
vector<int> e[100001];
int res[100001];
bool visited[100001];
int cnt=0;
queue<int> q;

void bfs(int v){
    visited[v]= true;
    q.push(v);
    cnt++;
    res[v]=cnt;

    while (!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int i=0;i<e[tmp].size();i++){
            if(!visited[e[tmp][i]] && e[tmp][i]){

                cnt++;
                visited[e[tmp][i]]= true;
                q.push(e[tmp][i]);
                res[e[tmp][i]]=cnt;
            }
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
    for(int i=1;i<=n;i++) {
        sort(e[i].begin(), e[i].end(),greater<int>());
    }
    bfs(r);
    for(int i=1;i<=n;i++) cout<<res[i]<<'\n';
}