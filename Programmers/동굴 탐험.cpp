#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

bool visited[200001];
vector<int> e[200001];
map<int,int> m;
set<int> res,s;

void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v]=true;
    res.insert(v);
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(auto& i:e[k]){
            if(!visited[i]){
                int prev=m[i];
                if(!visited[prev]){
                    s.insert(i);
                }
                else{
                    visited[i]=true;
                    res.insert(i);
                    q.push(i);
                }
            }
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    for(int i=0;i<path.size();i++){
        e[path[i][0]].push_back(path[i][1]);
        e[path[i][1]].push_back(path[i][0]);
    }
    for(int i=0;i<order.size();i++){
        m[order[i][1]]=order[i][0];
    }

    bfs(0);
    res.insert(0);

    while(true){
        int tmp_size=res.size();

        for(auto& k:s){
            if(!visited[k] && visited[m[k]]) {
                bfs(k);
                s.erase(k);
            }
        }

        // bfs를 돌렸는데도 변화가 없으면 false
        if(tmp_size==res.size()){
            answer=false;
            break;
        }
        // 모두 방문했으면 true
        if(res.size()==n){
            answer=true;
            break;
        }
    }

    return answer;
}