#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000000

int parent[1000001];
int cnt[1000001];

int find(int a){
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void merge(int a,int b){
    int aRoot=find(a); int bRoot= find(b);
    if(aRoot!=bRoot){
    cnt[aRoot] += cnt[bRoot];
    parent[bRoot]=aRoot;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    for(int i=0;i<=1000000;i++) {
        parent[i] = i;
        cnt[i]=1;
    }
    for (int i = 0; i < n; ++i) {
        char I; cin>>I;
        if(I=='I'){
            int a,b; cin>>a>>b;
            merge(a,b);
        }else if(I=='Q'){
            int b; cin>>b;
            cout<<cnt[find(b)]<<'\n';
        }
    }
}
