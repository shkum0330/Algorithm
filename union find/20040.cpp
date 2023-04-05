#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000000

int n,m;
int parent[10001];

int find(int a){
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void merge(int a,int b){
    int aRoot=find(a); int bRoot= find(b);
    parent[bRoot]=aRoot;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        parent[i]=i;
    }
    int res=0;
    for (int i = 1; i <= m; ++i) {
        int a,b; cin>>a>>b;
        if(find(a)==find(b)){
            res=i;
            break;
        }
        merge(a,b);
    }
    cout<<res<<'\n';
}
