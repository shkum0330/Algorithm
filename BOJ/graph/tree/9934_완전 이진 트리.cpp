#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int k;
int visited[10001];
vector<int> degree[11];

void makeTree(int depth,int start,int end){
    if (start>=end) return;
    int mid=(start+end)/2;
    degree[depth].push_back(visited[mid]);
    makeTree(depth+1,start,mid);
    makeTree(depth+1,mid+1,end);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>k;
    int nodes=pow(2,k)-1;
    for (int i = 0; i < nodes; ++i) {
        cin>>visited[i];
    }
    makeTree(0,0,nodes);

    for (int i = 0; i < k; ++i) {
        for (auto& l:degree[i]) {
            cout<<l<<' ';
        }
        cout<<'\n';
    }
}