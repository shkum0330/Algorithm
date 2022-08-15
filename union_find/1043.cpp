#include <bits/stdc++.h>
using namespace std;

int n,m;
int parent[51];
vector<int> v;
vector<int> participants[51];
int cnt;

int find(int a){
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void merge(int a,int b){
    int aRoot=find(a); int bRoot=find(b);
    parent[bRoot]=aRoot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;

    for(int i=1;i<=n;i++) parent[i]=i;

    int t; cin>>t;
    for(int i=0;i<t;i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    if(!v.empty()){
    for(int i=1;i<v.size();i++) {
        merge(v[i-1],v[i]);
      }
    }

    for(int i=0;i<m;i++){
        int numOfPerson; cin>>numOfPerson;
        for(int j=0;j<numOfPerson;j++){
            int tmp; cin>>tmp;
            participants[i].push_back(tmp);
        }
        int x=participants[i][0];
        for(int j=1;j<numOfPerson;j++){
           merge(x,participants[i][j]);
        }
        for(int j=0;j<numOfPerson;j++){
            if(find(v.begin(),v.end(),participants[i][j]) != v.end()){ // 진실을 아는 사람이 있으면?
                for(int k=0;k<participants[i].size();k++) merge(v[0],participants[i][k]);
            }
        }
    }

    for(int i=0;i<m;i++){
        bool check=true;
        for(int j=0;j<participants[i].size();j++){
            if(!v.empty()){
            if(find(v[0])==find(participants[i][j])){
                check=false;
                break;
                }
            }

        }
        if(check) cnt++;
    }
    cout<<cnt<<'\n';
}
