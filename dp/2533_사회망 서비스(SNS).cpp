#include <bits/stdc++.h>
using namespace std;

#define INF 1987654321

typedef long long ll;
typedef pair<int,int> pii;
int n;
vector<int> edge[1000001];
bool visited[1000001];
int dp[1000001][2];

void dfs(int vertex){
    visited[vertex]= true;
    dp[vertex][0]=1;
    for (auto e:edge[vertex]) {
        if(!visited[e]){
            dfs(e);
            dp[vertex][1] += dp[e][0];
            dp[vertex][0] += min(dp[e][0],dp[e][1]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n-1; ++i) {
        int a,b; cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1);

    cout<<min(dp[1][0],dp[1][1])<<'\n';
}