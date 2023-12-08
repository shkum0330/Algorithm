#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
vector<pii> v;
priority_queue<int,vector<int>,greater<int>> pq;
int n,d;
bool compare(const pii& a,const pii& b){
    return a.second<b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int a,b; cin>>a>>b;
        if(a>b) swap(a,b);
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(), compare);
    cin>>d;

    int res=0;
    for (int i = 0; i < n; ++i) {
        int start=v[i].first; int end=v[i].second;
        if(end-start>d) continue;
        pq.push(start);
        while (!pq.empty()){
            if(pq.top()+d>=end) {
                break;
            }
            else pq.pop();
        }
        if(res<pq.size()) res=pq.size();
    }
    cout<<res<<'\n';
}