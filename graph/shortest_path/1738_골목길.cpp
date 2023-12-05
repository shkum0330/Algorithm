#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1999999999

struct edge{
    int s,e,w;
}e[20001];
vector<pii> rev_e[101];
ll dist[101];
int route[101];
bool to_dest[101];
vector<int> route_v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m; cin>>n>>m;
    for (int i = 1; i <= m; ++i) {
        int a,b,c; cin>>a>>b>>c;
        e[i].s=a; e[i].e=b; e[i].w=-c;
       rev_e[b].push_back({a,-c});
    }

    queue<int> q;
    to_dest[n]=true;
    q.push(n);
    while (!q.empty()){
        int tmp=q.front(); q.pop();
        for(auto& k:rev_e[tmp]){
            int next=k.first;
            if(!to_dest[next]){
                q.push(next);
                to_dest[next]=true;
            }

        }
    }


    for (int i = 1; i <= n; ++i) {
        dist[i]=INF;
    }
    dist[1]=0;
    bool isNegativeCycle= false;
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            if(dist[e[j].e]>dist[e[j].s]+e[j].w && dist[e[j].s] != INF) {
                dist[e[j].e]=dist[e[j].s]+e[j].w;
                route[e[j].e]=e[j].s;
            }
        }
    }
    for(int j=1;j<=m;j++){
        if(dist[e[j].e]>dist[e[j].s]+e[j].w && dist[e[j].s] != INF && to_dest[e[j].e]){
            isNegativeCycle= true;
            break;
        }
    }

    if(isNegativeCycle) cout<<-1<<'\n';
    else if(dist[n]==INF) cout<<-1<<'\n';
    else {
        int tmp=n;
        while(tmp){
            route_v.push_back(tmp);
            tmp=route[tmp];
        }
        for (int i = route_v.size()-1; i >= 0; i--) {
            cout<<route_v[i]<<' ';
        }
    }
}
//5 5
//1 2 1
//2 3 2
//3 4 3
//4 2 4
//1 5 -100