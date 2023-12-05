#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m;
ll arr[4000001];
int treeN=1;
void update(int node,ll val){
    node += (treeN - 1);
    arr[node]=val;
    node /= 2;
    while(node>0){
        arr[node]=min(arr[node*2],arr[node*2+1]);
        node /= 2;
    }
}
ll get(int start,int end){
    start += treeN - 1;
    end += treeN - 1;
    ll res=9876543210;
    while(start<=end){
        if(start%2==1) res =min(res,arr[start]);
        if(end%2==0) res =min(res,arr[end]);
        start=(start+1)/2;
        end=(end-1)/2;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for (treeN = 1; treeN < n; treeN = treeN << 1);

    for(int i=0;i<n;i++) cin>>arr[i + treeN];
    for (int i = treeN + n; i < treeN * 2; ++i) {
        arr[i]=1999999999;
    }
    for(int i= treeN - 1; i > 0; i--){
        arr[i]= min(arr[i*2],arr[i*2+1]);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1) update(b,c);
        else if(a==2){
            if(b>c) swap(b,c);
            cout<<get(b,c)<<'\n';
        }
    }
}
