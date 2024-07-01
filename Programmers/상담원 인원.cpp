#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> consultants;
vector<int> tmp;

void dfs(int idx,int cnt,int k,int n){
    if(cnt==n-k){
        consultants.push_back(tmp);
        return;
    }
    
    for(int i=idx;i<k;i++){
        tmp[i]++;
        dfs(i,cnt+1,k,n);
        tmp[i]--;
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 987654321;
    
    for(int i=0;i<k;i++){
        tmp.push_back(1); // 반드시 1명이상 들어가야함
    }
    
    dfs(0,0,k,n);
  
    for(auto c:consultants){
        int tmp=0;
        priority_queue<int,vector<int>,greater<int>> pq[k];
        
        for(int i=0;i<k;i++){
            for(int j=0;j<c[i];j++) pq[i].push(0);
        }
        
        for(int i=0;i<reqs.size();i++){
            int start=reqs[i][0];
            int c_time=reqs[i][1];
            int type=reqs[i][2]-1;
            
            int p=pq[type].top();
            pq[type].pop();
            
            if(start>=p){
                pq[type].push(start+c_time);
            }else{
                tmp += p-start;
                pq[type].push(p+c_time);
            }
    
        }
        answer=min(answer,tmp);
    }
    
    return answer;
}
