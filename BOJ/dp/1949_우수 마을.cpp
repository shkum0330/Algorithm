#include <bits/stdc++.h>
using namespace std;

#define INF 1987654321

int n;
vector<int> people(10001);
vector<int> village[10001];
int dp[10001][2];
bool visited[10001];
void dfs(int vertex){
    visited[vertex]=true;
    dp[vertex][0]=people[vertex];
    for (int e:village[vertex]) {
        if(!visited[e]){
            dfs(e);
            dp[vertex][0]+=dp[e][1];
            dp[vertex][1]+=max(dp[e][0],dp[e][1]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>people[i];
    }
    for (int i = 0; i < n-1; ++i) {
        int a,b; cin>>a>>b;
        village[a].push_back(b);
        village[b].push_back(a);
    }
    dfs(1);
    cout<<max(dp[1][0],dp[1][1])<<'\n';
}