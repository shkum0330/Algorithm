#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int movex[4]={0,-1,0,1};
int movey[4]={-1,0,1,0};
int v[101][101];
bool visited[101][101];
int dist[101][101];


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n=maps.size();
    int m=maps[0].size();
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++) {
            v[i+1][j+1]=maps[i][j];
        }
    }
    dist[1][1]=1;
    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+movex[i];
            int ny=y+movey[i];
            if(ny>n || ny<=0 || nx>m || nx<=0) continue;
            if(!visited[ny][nx] && v[ny][nx]){
                q.push({ny,nx});
                visited[ny][nx]=true;
                dist[ny][nx]=dist[y][x]+1;
            }
        }
    }
    if(dist[n][m]==0) return -1;
    
    return dist[n][m];
}
