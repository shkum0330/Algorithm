#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int dist[20001];
bool visited[20001];
vector<int> e[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0;i<edge.size();i++){
        e[edge[i][0]].push_back(edge[i][1]);
        e[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<int> q;
    q.push(1);
    visited[1]=true;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int i=0;i<e[tmp].size();i++){
            int next=e[tmp][i];
            if(!visited[next]){
                q.push(next);
                dist[next]=dist[tmp]+1;
                visited[next]=true;
            }
        }
    }
    
    sort(dist+1,dist+n+1);
    for(int i=n;i>=1;i--){
        if(dist[i]!=dist[n]) break;
        answer++;
    }
    return answer;
}
