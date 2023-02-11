#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1999999999
int omok[20][20];
int mx[8]={-1,-1,-1,0,0,1,1,1};
int my[8]={0,-1,1,-1,1,-1,1,0};

bool check(int color,int y,int x,int d){
    int cnt=1;
    while(color==omok[y+my[d]][x+mx[d]]){
        cnt++;
        y+=my[d];
        x+=mx[d];
    }
    return (cnt == 5);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            cin>>omok[i][j];
        }
    }

    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            if(omok[i][j]){
                for (int k = 0; k < 4; ++k) {
                    int ny=i+my[k];
                    int nx=j+mx[k];

                    if((omok[ny][nx] != omok[i][j]) && check(omok[i][j],i,j,7-k)){
                        cout<<omok[i][j]<<'\n';
                        cout<<i+1<<" "<<j+1<<'\n';
                        exit(0);
                    }
                }
            }
        }
    }

    cout<<0<<'\n';

}
