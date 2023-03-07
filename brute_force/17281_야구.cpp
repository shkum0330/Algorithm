#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair<int,int> pii;
typedef long long ll;

int n,res;
vector<vector<int>> v;
int hitter[51][10];
void baseball(vector<int> order){
    int base[4];
    memset(base,0,sizeof(base));
    int score=0; int outCount=0;
    int num=0; // 타자 번호

    for (int i = 0; i < n; ++i) {
        while(true) {
            if(num == 9) num=0;
            if(outCount==3) {
                outCount=0;
                memset(base,0,sizeof(base));
                break;
            }
            if(hitter[i][order[num]] == 0){ // 아웃
                outCount++;
                num++;
            }
            else if(hitter[i][order[num]] == 1){ // 안타
                if(base[3]==1){
                    score++;
                    base[3]=0;
                }
                if(base[2]==1){
                    base[3]=1;
                    base[2]=0;
                }
                if(base[1]==1){
                    base[2]=1;
                    base[1]=0;
                }
                base[1]=1;
                num++;
            }
            else if(hitter[i][order[num]] == 2){
                if(base[3]==1){
                    score++;
                    base[3]=0;
                }
                if(base[2]==1){
                    score++;
                    base[2]=0;
                }
                if(base[1]==1){
                    base[3]=1;
                    base[1]=0;
                }
                base[2]=1;
                num++;
            }
            else if(hitter[i][order[num]] == 3){
                if(base[3]==1){
                    score++;
                    base[3]=0;
                }
                if(base[2]==1){
                    score++;
                    base[2]=0;
                }
                if(base[1]==1){
                    score++;
                    base[1]=0;
                }
                base[3]=1;
                num++;
            }
            else if(hitter[i][order[num]] == 4){
                int runner=0;
                for (int j = 1; j <= 3; ++j) {
                    if(base[j]==1){
                        runner++;
                        base[j]=0;
                    }
                }
                score += (runner+1);
                num++;
            }
        }
    }
    res=max(score,res);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cin>>hitter[i][j];
        }
    }
    vector<int> perm;
    for (int i = 2; i <= 9; ++i) {
        perm.push_back(i);
    }
    do{
        v.push_back(perm);
    } while (next_permutation(perm.begin(),perm.end()));
    for (int i = 0; i < v.size(); ++i) {
        vector<int> order;
        for (int j = 0; j < 3; ++j) {
            order.push_back(v[i][j]);
        }
        order.push_back(1);
        for (int j = 3; j < 8; ++j) {
            order.push_back(v[i][j]);
        }
        baseball(order);
    }
    cout<<res<<'\n';
}