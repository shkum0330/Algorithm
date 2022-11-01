#include <bits/stdc++.h>
using namespace std;


int field[101][101];
bool visited[101][101];
int cnt;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
queue<pair<int,int>> q;
int m,n,k;
int area;
vector<int> areaList;
void bfs(int y,int x){
    area++;
    q.push({y,x});
    visited[y][x]=true;

    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0 || ny>=m || nx<0 || nx>=n) continue;
            if(!visited[ny][nx] && field[ny][nx] == 0){
                area++;
                q.push({ny,nx});
                visited[ny][nx]=true;
            }

        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>m>>n>>k;
    for (int i = 0; i <k; ++i) {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        for (int j = y1; j < y2; ++j) {
            for (int l = x1; l < x2; ++l) {
                field[j][l]=1;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j]==0 && !visited[i][j]) {
                area=0;
                bfs(i,j);
                cnt++;
                if(area) areaList.push_back(area);
            }
        }
    }
    sort(areaList.begin(),areaList.end());
    cout<<cnt<<'\n';
    for (int i = 0; i < areaList.size(); ++i) {
        cout<<areaList[i]<<' ';
    }
    cout<<'\n';
}
