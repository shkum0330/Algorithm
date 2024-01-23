#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n,res;
int node[10001];
vector<int> trace,edge[10001];
int dp[10001][2];
bool visited[10001];

void dfs(int v){
    visited[v]=true;
    dp[v][1]=node[v];

    for (auto& k:edge[v]) {
        if(!visited[k]){
            dfs(k);
            dp[v][1] += dp[k][0];
            dp[v][0] += max(dp[k][0],dp[k][1]);
        }
    }
}

void tracking(int v,bool included,int prev){
    if(included){
        trace.push_back(v);
    }
    for (auto& k:edge[v]) {
        if(prev==k) continue;
        if(included){
            tracking(k,false,v);
        }else{
            tracking(k,dp[k][1]>dp[k][0],v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>node[i];
    }
    for (int i = 0; i < n-1; ++i) {
        int a,b; cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1);
    if(dp[1][0]>dp[1][1]){
        res=dp[1][0];
        tracking(1,false,-1);
    } else{
        res=dp[1][1];
        tracking(1,true,-1);
    }

    sort(trace.begin(),trace.end());
    cout<<res<<'\n';
    for (int i = 0; i < trace.size(); ++i) {
        cout<<trace[i]<<' ';
    }
    cout<<'\n';
}
