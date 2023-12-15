#include <bits/stdc++.h>
using namespace std;

#define INF 1987654321

typedef long long ll;
typedef pair<int,int> pii;

int n,m;
int arr[100001];
const int sz=1<<17;
vector<int> tree[1<<18];

void build(int node,int start,int end){
    if(start==end){
        tree[node].push_back(arr[start]);
        return;
    }
    int mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);

    vector<int> &l=tree[node*2];
    vector<int> &r=tree[node*2+1];

    tree[node].resize(l.size() + r.size());
    merge(l.begin(),l.end(),r.begin(),r.end(),tree[node].begin());

}

int query(int node, int start, int end, int l, int r, int x){
    if(l>end || r<start) return 0;
    if(l<=start && end<=r) return tree[node].size()-(upper_bound(tree[node].begin(),tree[node].end(),x)-tree[node].begin());
    int mid=(start+end)/2;
    return query(node *2,start,mid,l,r,x)+ query(node*2+1,mid+1,end,l,r,x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
    }
    build(1,1,n);
    cin>>m;
    int last_ans=0;
    for (int i = 0; i < m; ++i) {
        int a,b,c; cin>>a>>b>>c;
        a=a ^ last_ans;
        b=b ^ last_ans;
        c=c ^ last_ans;
        last_ans= query(1,1,n,a,b,c);
        cout<<last_ans<<'\n';
    }
}
