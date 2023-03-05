#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair<int,pair<int,int>> pii;
typedef long long ll;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int t,res,n;
int mmap[101][101];
int dist[101][101];
int cost[101][101];
bool visited[101][101];
priority_queue<pii,vector<pii>,greater<>> pq;
void dijkstra(){
    pq.push({0,{0,0}});

    while (!pq.empty()){
        pair<int,int> curr=pq.top().second;
        int y=pq.top().second.first;
        int x=pq.top().second.second;
        int currd=pq.top().first;
        pq.pop();
        for (int i = 0; i < 4; ++i) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=n || ny<0 ||nx>=n || nx<0) continue;
            if(dist[ny][nx]>currd+cost[ny][nx]){
                dist[ny][nx]=currd+cost[ny][nx];
                pq.push({dist[ny][nx],{ny,nx}});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    for (int tc = 1; tc <= t; ++tc) {
        memset(visited,0,sizeof(visited));
        memset(dist,0,sizeof(dist));
        while (!pq.empty()) pq.pop();
        cin>>n;
        for (int i = 0; i < n; ++i) {
            string s; cin>>s;
            for (int j = 0; j < n; ++j) {
                mmap[i][j]=s[j]-'0';
                dist[i][j]=INF;
                cost[i][j]=mmap[i][j];
            }
        }
        dijkstra();
        cout<<"#"<<tc<<" "<<dist[n-1][n-1]<<'\n';
    }
}