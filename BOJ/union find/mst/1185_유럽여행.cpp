#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

#define INF 987654321

struct st{
    int s,e,c;
}edge[100001];

int n,p,res;
int parent[10001];
int cost[10001];

bool compare(st a, st b){
    return a.c<b.c;
}

int find(int a){
    if(a==parent[a]) return a;
    else return parent[a]=find(parent[a]);
}

bool merge(int a,int b){
    int a_root=find(a); int b_root=find(b);
    if(a_root==b_root) return false;
    parent[b_root]=a_root;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>p;
    int start=INF;
    for (int i = 1; i <= n; ++i) {
        cin>>cost[i];
        start=min(start,cost[i]);
        parent[i]=i;
    }
    for (int i = 0; i < p; ++i) {
        int s,e,c; cin>>s>>e>>c;
        edge[i].s=s;
        edge[i].e=e;
        edge[i].c=cost[s]+cost[e]+2*c;
    }
    sort(edge,edge+p,compare);

    for (int i = 0; i < p; ++i) {
        if(merge(edge[i].s,edge[i].e)){
            res += edge[i].c;
        }
    }
    
    res += start;

    cout<<res<<'\n';
}
