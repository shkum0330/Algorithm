#include <bits/stdc++.h>
using namespace std;

#define INF 1999999999
typedef pair<int,int> pii;
struct edge{
    int start,end,time;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc; cin>>tc;
    while(tc--) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<edge> e;

        for (int i = 1; i <= m; i++) {
            int a, b, c;
            cin>>a>>b>>c;
            e.push_back({a, b, c});
            e.push_back({b, a, c});
        }
        for (int i = 0; i < w; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            e.push_back({a, b, -c});
        }

        int dist[n + 1];
        for (int i = 0; i <= n; i++) dist[i] = INF;
        bool isNegativeCycle = false;
        dist[1] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < e.size(); j++) {
                if (dist[e[j].end] > dist[e[j].start] + e[j].time)
                    dist[e[j].end] = dist[e[j].start] + e[j].time;
            }
        }
        for (int j = 0; j < e.size(); j++) {
            if (dist[e[j].end] > dist[e[j].start] + e[j].time){
                isNegativeCycle= true;
                break;
            }
        }
        if(isNegativeCycle) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
