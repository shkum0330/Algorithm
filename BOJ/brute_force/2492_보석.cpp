#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n,m,t,k,res,res_x,res_y;
vector<pii> diamond;
bool visited[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>t>>k;

    for (int i = 0; i < t; ++i) {
        int x,y; cin>>x>>y;
        diamond.push_back({x,y});
    }

    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            int x,y;
            if(diamond[i].first+k>n) x=n-k;
            else x=diamond[i].first;
            if(diamond[j].second+k>m) y=m-k;
            else y=diamond[j].second;

            int cnt=0;
            for (auto& d:diamond) {
                if(x <= d.first && d.first <= x + k && y <= d.second && d.second <= y + k) cnt++;
            }
            if(cnt>res){
                res=cnt;
                res_x=x; res_y=y+k;
            }

        }
        
    }
    
    cout<<res_x<<' '<<res_y<<'\n';
    cout<<res<<'\n';
    
}
