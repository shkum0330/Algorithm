#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n, tree_n;
vector<int> v;
vector<pii> player;
int tree[20000001];
pii res[500001];

int get(int start,int end){
    start += tree_n-1;
    end += tree_n;
    int ret=0;
    while (start<=end){
        if(start%2==1){
            ret += tree[start];
        }
        if(end%2==0){
            ret += tree[end];
        }
        start = (start+1)/2;
        end= (end-1)/2;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>n;
    for (int i = 0; i < n; ++i) {
        int p; cin>>p;
        v.push_back(p);
    }
    for (int i = 0; i < n; ++i) {
        player.push_back({v[i],i});
    }

    sort(player.begin(),player.end(),greater<>());

    for (tree_n = 1; tree_n < n; tree_n<<=1);

    for (int i = 0; i < n; ++i) {

        tree[tree_n+player[i].second]=1;

        int idx=(tree_n+player[i].second)/2;
        while (idx>0){
            tree[idx]=tree[idx*2]+tree[idx*2+1];
            idx /= 2;
        }

        res[i].first=player[i].second;
        res[i].second=get(1,player[i].second);
    }
    
    sort(res,res+n);
    for (int i = 0; i < n; ++i) {
        cout<<res[i].second<<'\n';
    }
    
    cout<<'\n';
}
