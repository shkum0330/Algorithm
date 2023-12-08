#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n,m,k,cnt,res;
int mmap[21][21];
int dice[7];
pii mov[4]={{0,1},{1,0},{0,-1},{-1,0}}; // 동 남 서 북
pii location;

void bfs(int y,int x,int val){
    queue<pii> q;
    bool visited[n+1][m+1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            visited[i][j]= false;
        }
    }
    cnt++;
    q.push({y,x});
    visited[y][x]=true;
    while (!q.empty()){
        int yy=q.front().first;
        int xx=q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny=yy+mov[i].first;
            int nx=xx+mov[i].second;
            if(ny>n || ny<=0 || nx>m || nx<=0) continue;
            if(!visited[ny][nx] && mmap[ny][nx]==val){
                cnt++;
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }
}
void moving(int dir){
    int newDice[7];
    if(dir==0){ // 동
        newDice[1]=dice[4]; newDice[2]=dice[2]; newDice[3]=dice[1]; newDice[4]=dice[6]; newDice[5]=dice[5]; newDice[6]=dice[3];
    }
    if(dir==1){ // 남
        newDice[1]=dice[5]; newDice[2]=dice[1]; newDice[3]=dice[3]; newDice[4]=dice[4]; newDice[5]=dice[6]; newDice[6]=dice[2];
    }
    if(dir==2){ // 서
        newDice[1]=dice[3]; newDice[2]=dice[2]; newDice[3]=dice[6]; newDice[4]=dice[1]; newDice[5]=dice[5]; newDice[6]=dice[4];
    }
    if(dir==3){ // 북
        newDice[1]=dice[2]; newDice[2]=dice[6]; newDice[3]=dice[3]; newDice[4]=dice[4]; newDice[5]=dice[1]; newDice[6]=dice[5];
    }

    for (int i = 1; i <= 6; ++i) {
        dice[i]=newDice[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>m>>k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>mmap[i][j];
        }
    }

    for (int i = 1; i <= 6; ++i) {
        dice[i]=i;
    }
    dice[2]=5;
    dice[5]=2;
    location={1,1};
    int dir=0;

    for (int i = 0; i < k; ++i) {
        cnt=0;
        if(location.first+mov[dir].first>n || location.first+mov[dir].first<=0 || location.second+mov[dir].second>m || location.second+mov[dir].second<=0) {
            dir+=2;
            if(dir>3) dir-=4;

        }

        location.first += mov[dir].first;
        location.second += mov[dir].second;
        moving(dir);

        int tmp=mmap[location.first][location.second];

        if(dice[6]>tmp){
            dir++;
            if(dir==4) dir=0;
        }
        if(dice[6]<tmp){
            dir--;
            if(dir==-1) dir=3;
        }
        bfs(location.first,location.second,tmp);

        res += (cnt*tmp);
    }
    cout<<res<<'\n';
}