#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000000

int parent[100001];
int g,p;

int find(int a){
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void merge(int a,int b){
    int aRoot=find(a); int bRoot= find(b);
    parent[bRoot]=aRoot;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>g>>p;

    for (int i = 1; i <= g; ++i) {
        parent[i]=i;
    }

    int res=0;
    for (int i = 0; i < p; ++i) {
        int airplane; cin>>airplane;
        int f= find(airplane);
        if(f!=0){
            merge(f-1,f);
            res++;
        }else break;
    }
    cout<<res<<'\n';
}

