#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair<int,int> pii;
typedef long long ll;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int t,res,n,m,c;
int honey[11][11];
int dp[11][11];
bool visited[11][11];

struct Basket{
    int y,x,value;
};
vector<pair<pii,int>> v;
vector<int> basket;
vector<int> s;
bool compare(const Basket& a, const Basket& b){
    return a.value>b.value;
};
void subset(int y,int x,int idx){

    if(idx==m){
        int sum=0;
        for (int i = 0; i < s.size(); ++i) {
            sum+=s[i];
        }
        if(sum>c) return;
        else {
            int getHoney=0;
            for (int i = 0; i < s.size(); ++i) {
                getHoney += pow(s[i],2);
            }
            basket.push_back(getHoney);
            return;
        }
    }


    subset(y,x,idx+1);
    s.push_back(honey[y][x+idx]);
    subset(y,x,idx+1);
    s.pop_back();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    for (int tc = 1; tc <= t; ++tc) {
        res=0;
        cin>>n>>m>>c;
        v.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>honey[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n-m+1; ++j) {
                s.clear();
                basket.clear();
                subset(i,j,0);
                int maxHoney=0;
                for (int b:basket) {
                    maxHoney=max(maxHoney,b);
                }
                v.push_back({{i,j},maxHoney});
            }
        }
        for (int i = 0; i < v.size()-1; ++i) {
            for (int j = i+1; j < v.size(); ++j) {
                if(v[i].first.first== v[j].first.first && abs(v[i].first.second-v[j].first.second)<m) continue;
                res=max(res,v[i].second+v[j].second);
            }
        }
        cout<<"#"<<tc<<" "<<res<<'\n';
    }
}