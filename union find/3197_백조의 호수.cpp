#include <bits/stdc++.h>
using namespace std;

#define INF 1987654321

typedef pair<int,int> pii;

int r,c,res;

int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
char lake[1501][1501];
bool visited[1501][1501];
pii parent[1501][1501];
pii swan1, swan2;
vector<pii> v; // 녹여야 하는 얼음 목록

pii find(int y,int x){
    if(parent[y][x].first==y && parent[y][x].second==x) return {y,x};
    else return parent[y][x]=find(parent[y][x].first,parent[y][x].second);
}

void merge(pii a,pii b){
    pii aRoot=find(a.first,a.second); pii bRoot=find(b.first,b.second);
    parent[bRoot.first][bRoot.second]=aRoot;
}

bool check(pii a,pii b){
    if(find(swan1.first,swan1.second)==find(swan2.first,swan2.second)) return true;
    else return false;
}

void dfs(int y,int x,pii prev){
    visited[y][x]=true;
    merge(prev,{y,x});
    for (int i = 0; i < 4; ++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny>=r || ny<0 || nx>=c || nx<0) continue;
        if(visited[ny][nx] && lake[ny][nx] != 'X') merge({ny,nx},{y,x});
        if(!visited[ny][nx] && lake[ny][nx] != 'X') dfs(ny,nx,{y,x});
    }
}

void melt(){ // bfs로 녹이는게 더 효율적이나, 이 방법도 가능은 하다.
    // 꼭짓점에 있는 얼음 녹이기
    if(lake[0][0]=='X' && (lake[0][1]!='X' || lake[1][0]!='X')) v.push_back({0,0});
    if(lake[0][c-1]=='X' &&(lake[0][c-2]!='X' || lake[1][c-1]!='X')) v.push_back({0,c-1});
    if(lake[r-1][0]=='X' &&(lake[r-1][1]!='X' || lake[r-2][0]!='X')) v.push_back({r-1,0});
    if(lake[r-1][c-1]=='X' &&(lake[r-2][c-1]!='X' || lake[r-1][c-2]!='X')) v.push_back({r-1,c-1});

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if((i==0 && j==0) || (i==0 && j==c-1) || (i==r-1 && j==0) || (i==r-1 && j==c-1)) continue;
            if(lake[i][j]=='X'){
                if(i==0){
                    if(lake[i+1][j]!='X' || lake[i][j+1]!='X' || lake[i][j-1]!='X') v.push_back({i,j});
                }
                else if(i==r-1){
                    if(lake[i-1][j]!='X' || lake[i][j+1]!='X' || lake[i][j-1]!='X') v.push_back({i,j});
                }
                else if(j==0){
                    if(lake[i+1][j]!='X' || lake[i-1][j]!='X' || lake[i][j+1]!='X') v.push_back({i,j});
                }
                else if(j==c-1){
                    if(lake[i+1][j]!='X' || lake[i-1][j]!='X' || lake[i][j-1]!='X') v.push_back({i,j});
                }else{
                    if(lake[i+1][j]!='X' || lake[i-1][j]!='X' || lake[i][j+1]!='X' || lake[i][j-1]!='X') v.push_back({i,j});
                }
            }
        }
    }

    for (auto& k: v){
        lake[k.first][k.second]='.';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>r>>c;
    bool flag=true;

    for (int i = 0; i < r; ++i) { // 입력
        for (int j = 0; j < c; ++j) {
            cin>>lake[i][j];
            if(lake[i][j]=='L'){
                if(flag) {
                    swan1 = {i, j};
                    flag=false;
                }else{
                    swan2 = {i, j};
                }
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            parent[i][j]={i,j};
        }
    }
    for (int i = 0; i < r; ++i) { // 얼음이 아닌 부분 dfs로 유니온 파인드
        for (int j = 0; j < c; ++j) {
            if(!visited[i][j] && lake[i][j] != 'X') dfs(i,j,{i,j});
        }
    }

    // 백조 두 마리가 갖은 부모를 가질 때(== 만날 수 있을 때)
    while (!check(swan1,swan2)){
        melt();
        for (auto& k:v) {
            if(!visited[k.first][k.second]) dfs(k.first,k.second,k);
        }
        v.clear();
        res++;
    }
    cout<<res<<'\n';
}
