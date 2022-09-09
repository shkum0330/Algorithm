#include <bits/stdc++.h>
using namespace std;

int n,m;
int parent[10001];
vector<int> v;
int cnt;

int find(int a){
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void merge(int a,int b){
    int aRoot=find(a); int bRoot=find(b);
    parent[bRoot]=aRoot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        merge(a,b);
    }

    for(int i=0;i<n;i++){
        int num; cin>>num;
        v.push_back(num);
    }
    for(int i=1;i<v.size();i++){
        if(find(v[i-1])!=find(v[i])) cnt++;
    }
    cout<<cnt<<'\n';
}
