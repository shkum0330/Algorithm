#include <bits/stdc++.h>
using namespace std;

int n,m;
string inputStr[251];
char field[251][251];
queue<pair<int,int>> q;
bool visited[251][251];
int movex[4]={0,1,0,-1}; // 좌우
int movey[4]={-1,0,1,0}; // 상하
int numOfSheep;
int numOfWolf;

void bfs(int y,int x){
    int sheep=0; int wolf=0;
    if(field[y][x]=='o') sheep++;
    if(field[y][x]=='v') wolf++;
    visited[y][x]= true;
    q.push({y,x});

    while(!q.empty()){
        int tmpy=q.front().first;
        int tmpx=q.front().second;

        q.pop();

        for(int i=0;i<4;i++) {
            int nx= tmpx+movex[i];
            int ny= tmpy+movey[i];
            if(nx>=m || nx<0|| ny>=n || ny<0) continue;

            if(field[ny][nx]!='#' && !visited[ny][nx]){
                visited[ny][nx]= true;
                if(field[ny][nx]=='o') sheep++;
                if(field[ny][nx]=='v') wolf++;
                q.push({ny,nx});
            }

        }
    }
    if(sheep>wolf){
        numOfWolf -= wolf;
    } else{
        numOfSheep -= sheep;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;

    for(int i=0;i<n;i++) cin>>inputStr[i];

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            if(inputStr[i][j]=='.') field[i][j]='.';
            else if(inputStr[i][j]=='o') {
                field[i][j]='o'; numOfSheep++;
            }
            else if(inputStr[i][j]=='v') {
                field[i][j]='v'; numOfWolf++;
            }
            else if(inputStr[i][j]=='#') field[i][j]='#';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(field[i][j] != '#' && !visited[i][j]) bfs(i,j);
        }
    }

    cout<<numOfSheep<<' '<<numOfWolf<<'\n';
}
