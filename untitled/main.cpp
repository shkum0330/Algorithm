#include <bits/stdc++.h>
using namespace std;

struct nations{
    int num,gold,silver,bronze,rank;
};
bool compare(const nations& a,const nations& b){
    if(a.gold != b.gold) return a.gold>b.gold;
    else if(a.silver != b.silver) return a.silver>b.silver;
    else return a.bronze>b.bronze;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k; cin>>n>>k;
    nations nation[n];
    for(int i=0;i<n;i++){
        cin>>nation[i].num>>nation[i].gold>>nation[i].silver>>nation[i].bronze;
    }
    sort(nation,nation+n, compare);

    int rank=1;
    nation[0].rank=rank;
    for(int i=1;i<n;i++){
        rank++;
        if(nation[i].gold<nation[i-1].gold) nation[i].rank=rank;
        else if(nation[i].silver<nation[i-1].silver) nation[i].rank=rank;
        else if(nation[i].bronze<nation[i-1].bronze) nation[i].rank=rank;
        else nation[i].rank=nation[i-1].rank;
    }
    for(int i=0;i<n;i++){
        if(nation[i].num==k) cout<<nation[i].rank<<'\n';
    }
}