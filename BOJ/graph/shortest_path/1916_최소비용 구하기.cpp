#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000000

int n,m;
vector<pii> e[1001];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int dist[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int a,b,c; cin>>a>>b>>c;
        e[a].push_back({b,c});
    }
    int start,end; cin>>start>>end;
    for (int i = 1; i <= n; ++i) {
        dist[i]=INF;
    }
    pq.push({0,start});
    dist[start]=0;
    while (!pq.empty()){
        int curr=pq.top().second; int currd=pq.top().first;
        pq.pop();
        if(dist[curr]<currd) continue;
        for(auto k:e[curr]){
            int next=k.first; int nextd=k.second;
            if(dist[next]>currd+nextd){
                dist[next]=currd+nextd;
                pq.push({dist[next],next});
            }
        }
    }
    cout<<dist[end]<<'\n';
}

