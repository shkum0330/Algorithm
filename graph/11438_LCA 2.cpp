#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v[100001];
int depth[100001];
int parent[18][100001];

void bfs(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int next: v[curr]){
            if(depth[next]==-1){
                q.push(next);
                depth[next]=depth[curr]+1;

                parent[0][next]=curr;
            }
        }
    }
}


void makeTable(){
    for(int i=1;i<18;i++){
        for(int j=1;j<=n;j++){
            parent[i][j]= parent[i-1][parent[i-1][j]]; // parent[i][j]는 parent[i-1][j]의 2^(i-1)번째 부모
        }
    }
}

int LCA(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);
    int diff=depth[a]-depth[b];
    for(int i=0;diff;i++){
        if(diff & 1){
            a=parent[i][a];
        }
        diff>>=1;
    }

    while(a!=b){
        int r;
        for(r=0;r<18;r++){
            if(parent[r][a]==parent[r][b]) break;
        }
        if(r>0) r--;
        a=parent[r][a]; b=parent[r][b];
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++) depth[i]=-1;
    depth[1]=0;

    bfs();
    makeTable();
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        cout<<LCA(a,b)<<'\n';
    }
}