#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
int n;

ll mul(ll x,ll y){
    if(y==0) return 1;
    else if(y==1) return x%MOD;
    ll tmp= mul(x, y / 2) % MOD;
    if(y%2==0) return tmp * tmp % MOD;
    else return tmp * tmp % MOD * x % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    ll res=0;
    for(int i=0;i<n;i++) {
        ll c,k; cin>>c>>k;
        res+= (c*k%MOD)*mul(2,k-1) % MOD;
    }
    cout<<res%MOD<<'\n';
}