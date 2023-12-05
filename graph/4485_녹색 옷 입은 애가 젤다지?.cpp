#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,pair<int,int>> pii;
#define INF 1999999999

int n;
vector<pii> d[126][126];
int cost[126][126];
int dist[126][126];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int movex[4]={0,-1,0,1};
int movey[4]={-1,0,1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int num=1;
    while (true) {
        cin >> n;
        if(n==0) break;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j) {
                cin>>cost[i][j];
                dist[i][j]=INF;
            }
        }
        dist[0][0]=cost[0][0];
        pq.push({cost[0][0],{0,0}});

        while (!pq.empty()) {
            pair<int,int> curr = pq.top().second;
            int currx=pq.top().second.second;
            int curry=pq.top().second.first;
            int currd = pq.top().first;

            pq.pop();
            for (int i = 0; i < 4; ++i) {
                int nx=currx+movex[i];
                int ny=curry+movey[i];
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if(dist[ny][nx]>currd+cost[ny][nx]){
                    dist[ny][nx]=currd+cost[ny][nx];
                    pq.push({dist[ny][nx],{ny,nx}});
                }
            }
        }

        cout<<"Problem "<<num<<": "<<dist[n-1][n-1]<<'\n';
        num++;
    }
}