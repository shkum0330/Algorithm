#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000000

int n,m;
int parent[1001];
bool visited[1001];

int find(int a){
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void merge(int a,int b){
    int aRoot=find(a); int bRoot= find(b);
    parent[bRoot]=aRoot;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        parent[i]=i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int tmp; cin>>tmp;
            if(tmp) merge(i,j);
        }
    }
    vector<int> v;
    for (int i = 0; i < m; ++i) {
        int tmp; cin>>tmp; v.push_back(tmp);
    }
    int root= find(v[0]);
    bool flag=true;
    for (int i = 1; i < v.size(); ++i) {
        if(root != find(v[i])) flag= false;
    }
    if(flag) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}