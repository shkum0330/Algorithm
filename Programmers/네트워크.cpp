#include <string>
#include <vector>
#include <iostream>

using namespace std;
int e[201][201];
bool visited[201];

void dfs(int v,int n){
    visited[v]=true;
    for(int i=1;i<=n;i++){
        if(!visited[i]&&e[v][i]) dfs(i,n);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[i].size();j++){
            if(computers[i][j]) e[i+1][j+1]=1;
        }
    }
    for(int i=1;i<=n;i++){
        
        if(!visited[i]){
            answer++;
            dfs(i,n);
        }
    }
    return answer;
}
