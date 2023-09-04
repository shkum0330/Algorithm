#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

typedef long long ll;
typedef pair<int,int> pii;

int t,h,w,res;
char mmap[101][101];
bool visited[101][101];
bool door_visited[101][101];
bool key[26];
vector<pii> startingPoint;
vector<pii> blocked[26];
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};

void bfs(int y,int x){
    queue<pii> q;
    if(mmap[y][x]>='A' && mmap[y][x]<='Z'){
        if(!key[tolower(mmap[y][x])-'a']) {
            blocked[mmap[y][x] - 'A'].push_back({y, x}); // 막힘 표시, 열쇠 찾으면 다시 탐색
            door_visited[y][x]= true;
            return;
        }
        mmap[y][x]='.';
    }
    if(mmap[y][x]>='a' && mmap[y][x]<='z'){
        for (auto& k:blocked[toupper(mmap[y][x])-'A']) {
            if(door_visited[k.first][k.second]) q.push({k.first,k.second});
        }
        blocked[toupper(mmap[y][x]-'A')].clear();
        key[mmap[y][x]-'a']= true;
        mmap[y][x]='.';
    }
    if(mmap[y][x]=='$'){
        res++;
        mmap[y][x]='.';
    }

    visited[y][x]= true;
    q.push({y,x});

    while (!q.empty()){
        int yy=q.front().first;
        int xx=q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny=yy+dy[i];
            int nx=xx+dx[i];
            if(ny>=h || ny<0 || nx>=w || nx<0) continue;
            if(mmap[ny][nx] != '*' && !visited[ny][nx]) {
                if(mmap[ny][nx]>='A' && mmap[ny][nx]<='Z'){ // 문에 도달했을때
                    if(!key[tolower(mmap[ny][nx])-'a']) { // 열쇠가 없으면
                        blocked[mmap[ny][nx] - 'A'].push_back({ny, nx}); // 막힌 부분 좌표를 따로 저장해서 열쇠 찾으면 다시 탐색
                        door_visited[ny][nx]= true; // 문은 방문 처리를 따로 해준다.
                        continue;
                    }
                    else { // 있으면
                        mmap[ny][nx]='.';
                    }
                }
                if(mmap[ny][nx]>='a' && mmap[ny][nx]<='z'){
                    key[mmap[ny][nx]-'a']= true;
                    for (auto& k:blocked[toupper(mmap[ny][nx])-'A']) {
                        if(door_visited[k.first][k.second]) q.push({k.first,k.second});
                    }
                    blocked[toupper(mmap[y][x]-'A')].clear();
                    mmap[ny][nx]='.';
                }
                if(mmap[ny][nx]=='$'){
                    res++;
                    mmap[ny][nx]='.';
                }

                visited[ny][nx]= true;
                q.push({ny,nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while (t--){
        res=0;
        memset(key,false,26);
        for (int i = 0; i < 26; ++i) {
            blocked[i].clear();
        }
        startingPoint.clear();
        cin>>h>>w;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                visited[i][j]= false;
            }
        }
        for (int i = 0; i < h; ++i) {
            string s; cin>>s;
            for (int j = 0; j < w; ++j) {
                mmap[i][j]=s[j];
            }
        }
        string k; cin>>k;
        if(k != "0") {
            for (int i = 0; i < k.size(); ++i) {
                key[k[i] - 'a'] = true;
            }
        }

        for (int i = 0; i < w; ++i) {
            if(mmap[0][i]!='*'){
                startingPoint.push_back({0, i});
            }
            if(mmap[h-1][i]!='*'){
                startingPoint.push_back({h-1, i});
            }
        }
        for (int i = 1; i < h-1; ++i) {
            if(mmap[i][0]!='*'){
                startingPoint.push_back({i, 0});
            }
            if(mmap[i][w-1]!='*'){
                startingPoint.push_back({i, w-1});
            }
        }
        for (auto& k:startingPoint) {
            bfs(k.first,k.second);
        }
        cout<<res<<'\n';
    }

}
