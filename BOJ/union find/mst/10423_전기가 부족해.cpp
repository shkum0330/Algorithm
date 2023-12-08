#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000000

struct st{
    int s,e,c;
};
vector<st> e,mst;
bool compare(st a, st b) {
    return a.c < b.c;
}
int cost,res;
int parent[1001];
vector<int> gen;
int n,m,k;

int find(int a){
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
int merge(int a,int b){
    int aRoot=find(a); int bRoot= find(b);
    if(aRoot==bRoot) return 0;
    parent[bRoot]=aRoot;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>k;
    for (int i = 0; i < k; ++i) {
        int a; cin>>a; gen.push_back(a);
    }

    for (int i = 0; i < m; ++i) {
        int a,b,c; cin>>a>>b>>c;
        e.push_back({a,b,c});
    }
    for (int i = 1; i < k; ++i) {
        merge(gen[i-1],gen[i]);
        e.push_back({gen[i-1],gen[i],0});
    }

    for (int i = 0; i <= n; ++i) {
        parent[i]=i;
    }
    sort(e.begin(),e.end(), compare);
    int cnt=0;
    for (int i = 0; i < e.size(); ++i) {
        if(merge(e[i].s,e[i].e)){
            cost+=e[i].c;
        }

    }

    cout<<cost<<'\n';
}
