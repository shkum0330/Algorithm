#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n,k;
int res=INF;
bool visited[200002];
int pre[100001];
queue<pair<int,int>> q;

void bfs(int v) {
    q.push({v, 0});
    visited[v]=true;

    while (!q.empty()){
        int curr=q.front().first;
        int time=q.front().second;
        if(curr==k){
            res=time;
            return;
        }

        q.pop();
        if(!visited[curr*2] && curr*2<=100000){
            visited[curr*2]=true;
            q.push({curr*2,time+1});
            pre[curr*2]=curr;
        }
        if(!visited[curr+1] && curr+1<=100000){
            visited[curr+1]=true;
            q.push({curr+1,time+1});
            pre[curr+1]=curr;
        }
        if(!visited[curr-1] && curr-1>=0){
            visited[curr-1]=true;
            q.push({curr-1,time+1});
            pre[curr-1]=curr;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>k;

    bfs(n);
    vector<int> v;
    v.push_back(k);
    for (int i = 0; i < res; ++i) {
        v.push_back(pre[k]);
        k=pre[k];
    }
    
    cout<<res<<'\n';
    for (int i = v.size()-1; i >= 0; i--) {
        cout<<v[i]<<' ';
    }
    cout<<'\n';
}
