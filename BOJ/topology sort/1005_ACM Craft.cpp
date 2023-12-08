#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
int d[1001];
int inDegree[1001];
int res[1001];
vector<int> order[1001];
int t,n,k,w;
void topologySort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0) q.push(i);
        res[i]=d[i];
    }
    for(int i=1;i<=n;i++) {
        int x = q.front();
        q.pop();
        for (int j = 0; j < order[x].size(); j++) {
            int y = order[x][j];
            inDegree[y]--;
            res[y] = max(res[y], res[x] + d[y]);
            if (inDegree[y] == 0) q.push(y);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>t;
    while (t--){
        cin>>n>>k;
        for (int i = 1; i <= n; ++i) {
            cin>>d[i];
        }
        for (int i = 0; i < k; ++i) {
            int a,b; cin>>a>>b;
            order[a].push_back(b);
            inDegree[b]++;
        }
        cin>>w;

        topologySort();
        for (int i = 0; i < 1001; ++i) {
            order[i].clear();
        }
        cout<<res[w]<<'\n';
    }
}