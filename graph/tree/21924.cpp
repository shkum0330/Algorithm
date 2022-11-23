#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000000

int n,m;
int parent[100001];

struct st{
    int s,e,c;
};
vector<st> arr;
bool compare(st a, st b) {
    return a.c < b.c;
}

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
    cin>>n>>m;
    ll initCost=0;
    ll res=0;
    bool isConnected=true;
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin >> a>>b>>c;
        arr.push_back({a,b, c});
        initCost += c;
    }

    for (int i = 1; i <= n; i++) parent[i] = i;
    sort(arr.begin(),arr.end(), compare);
    for (int i = 0; i < arr.size(); ++i) {
        if(merge(arr[i].s,arr[i].e)) res += arr[i].c;
    }
    for (int i = 2; i <= n; ++i) {
        if(find(1) != find(i)) isConnected= false;
    }
    if(isConnected)cout<<initCost-res<<'\n';
    else cout<<-1<<'\n';
}

