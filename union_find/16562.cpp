#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000000

int n,m,k;
int money[10001];
int parent[10001];

int find(int a){
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void merge(int a,int b){
    int aRoot=find(a); int bRoot= find(b);
    money[aRoot]=min(money[aRoot],money[bRoot]);
    parent[bRoot]=aRoot;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>k;
    int cost=0;
    for (int i = 1; i <= n ; ++i) {
        cin>>money[i];
        parent[i]=i;
    }
    for (int i = 0; i < m; ++i) {
        int a,b; cin>>a>>b;
        merge(a,b);
    }
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(find(i));
    }

    for (auto i:s) {
        k -= money[i];
        cost+=money[i];
    }
    if(k<0) cout<<"Oh no"<<'\n';
    else cout<<cost<<'\n';
}