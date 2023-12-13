#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

typedef long long ll;
typedef pair<int,int> pii;

struct shark {
    int r, c, speed, dir, size; // r,c,속력,방향(1234 상하우좌),크기
    bool dead; // 죽었는지 여부
};

int r,c,m,res;
vector<shark> sharks;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};
priority_queue<pii,vector<pii>,greater<pii>> pq[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>r>>c>>m;
    for (int i = 0; i < m; ++i) {
        shark shark;
        cin >> shark.r >> shark.c >> shark.speed >> shark.dir >> shark.size;
        shark.dead=false;
        sharks.push_back(shark);
        pq[shark.r][shark.c].push({shark.size,i}); // {사이즈, 인덱스} 저장
    }
    int div=r+c;
    for (int i = 1; i <=c ; ++i) {

        // 상어 낚시하기
        for (int j = 1; j <= r; ++j) {
            if(!pq[j][i].empty()){
                res += pq[j][i].top().first;
                sharks[pq[j][i].top().second].dead=true;
                pq[j][i].pop();
                break;
            }
        }
        for (int j = 1; j <= r; ++j) {
            for (int k = 1; k <= c; ++k) {
                while (!pq[j][k].empty()) pq[j][k].pop();
            }
        }

        // 상어 이동
        for (int j=0; j < sharks.size(); j++) {
            if(sharks[j].dead) continue;
            int dist;
            if(sharks[j].dir==1 || sharks[j].dir==2){
                dist= sharks[j].speed%(r*2-2);
            }
            if(sharks[j].dir==3 || sharks[j].dir==4){
                dist= sharks[j].speed%(c*2-2);
            }
            for (int k = 0; k < dist; ++k) { // 상어 이동시키기
                // 방향 설정
                if(sharks[j].r == 1 && sharks[j].dir == 1){
                    sharks[j].dir=2;
                }
                if(sharks[j].r == r && sharks[j].dir == 2){
                    sharks[j].dir=1;
                }
                if(sharks[j].c == 1 && sharks[j].dir == 4){
                    sharks[j].dir=3;
                }
                if(sharks[j].c == c && sharks[j].dir == 3){
                    sharks[j].dir=4;
                }

                sharks[j].r += dy[sharks[j].dir - 1];
                sharks[j].c += dx[sharks[j].dir - 1];
            }
            pq[sharks[j].r][sharks[j].c].push({sharks[j].size, j});
        }

        // 각 칸에 상어 하나씩만 남기기
        for (int j = 1; j <= r; ++j) {
            for (int k = 1; k <= c; ++k) {
                if(!pq[j][k].empty() && pq[j][k].size()>1){
                    while (pq[j][k].size()!=1){
                        sharks[pq[j][k].top().second].dead=true;
                        pq[j][k].pop();
                    }
                }
            }
        }
    }

    cout<<res<<'\n';
}