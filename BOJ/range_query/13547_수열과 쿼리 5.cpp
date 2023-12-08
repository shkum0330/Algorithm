#include <bits/stdc++.h>
using namespace std;

#define INF 1987654321

typedef long long ll;
int n,m,sq,len;
int num[1000001];
int res[1000001];
struct Query{
    int idx,s,e;
};
bool compare(const Query& x, const Query& y){
    if(x.s/sq != y.s/sq) return x.s/sq < y.s/sq;
    return x.e<y.e;
}

vector<int> v;
vector<Query> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; sq=sqrt(n);
    v.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>v[i];
    }
    cin>>m;
    for (int i = 0; i < m; ++i) {
        int a,b; cin>>a>>b;
        q.push_back({i,a,b});
    }
    sort(q.begin(),q.end(), compare);
    int s=q[0].s; int e=q[0].e;
    for (int i = s; i <= e; ++i) {
        if(num[v[i]]==0) len++;
        num[v[i]]++;
    }
    res[q[0].idx]=len;
    for (int i = 1; i < m; ++i) {
        while (s<q[i].s){ // 삭제
            num[v[s]]--;
            if(num[v[s]]==0){
                len--;
            }
            s++;
        }
        while (e>q[i].e){ // 삭제
            num[v[e]]--;
            if(num[v[e]]==0){
                len--;
            }
            e--;
        }
        while (s>q[i].s){ // 추가
            s--;
            if(num[v[s]]==0) len++;
            num[v[s]]++;
        }
        while (e<q[i].e){ // 추가
            e++;
            if(num[v[e]]==0) len++;
            num[v[e]]++;
        }
        res[q[i].idx]=len;
    }
    for (int i = 0; i < m; ++i) {
        cout<<res[i]<<'\n';
    }
}
