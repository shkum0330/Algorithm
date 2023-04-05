#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000000

struct st{
    int s,e,c;
};

bool compare(st a, st b) {
    return a.c < b.c;
}
int init,res;
int parent[200001];
int m,n;
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
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        vector<st> v;
        init=0; res=0;
        for (int i = 0; i <= m; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b>>c;
            v.push_back({a, b, c});
            init += c;
        }

        sort(v.begin(), v.end(), compare);
        for (int i = 0; i < v.size(); ++i) {
            if (merge(v[i].s, v[i].e)) {
                res += v[i].c;
            }
        }

        cout << init - res << '\n';
    }
}
