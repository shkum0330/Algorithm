#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007
typedef pair<int,int> pii;

int n;
int res=INF;
char mmap[51][51];
int hmap[51][51];
vector<int> height;
pii mv[8]={{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1}};
bool visited[51][51];
bool flag;
pii p;
set<pii> k;

void bfs(int low,int high){
    queue<pii> q;
    q.push({p.first,p.second});
    visited[p.first][p.second]=true;
    int cnt=0;

    while (!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        if(mmap[y][x]=='K'){
            cnt++;
            if(cnt==k.size()){
                flag=true;
                return;
            }
        }
        for (int i = 0; i < 8; ++i) {
            int ny=y+mv[i].first;
            int nx=x+mv[i].second;
            if(ny>=n || ny<0 || nx>=n || nx<0) continue;
            if(!visited[ny][nx]){
                if(hmap[ny][nx]<low || hmap[ny][nx]>high) continue;
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>n;
    for (int i = 0; i < n; ++i) {
        string s; cin>>s;
        for (int j = 0; j < n; ++j) {
            mmap[i][j]=s[j];
            if(mmap[i][j]=='P') {
                p = {i, j};
            }
            if(mmap[i][j]=='K') k.insert({i,j});
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int h; cin>>h;
            height.push_back(h);
            hmap[i][j]=h;
        }
    }

    sort(height.begin(),height.end());
    height.erase(unique(height.begin(),height.end()),height.end());

    int left=0; int right=0;

    while (right<height.size()){
        while (true){
            if(height[left]>hmap[p.first][p.second] || height[right]<hmap[p.first][p.second]) break;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    visited[i][j]=false;
                }
            }
            flag=false;
            bfs(height[left],height[right]);

            if(!flag) break;

            res=min(res,height[right]-height[left]);
            left++;
        }
        right++;
    }
    cout<<res<<'\n';
}

