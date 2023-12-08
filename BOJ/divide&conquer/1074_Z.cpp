#include <bits/stdc++.h>
using namespace std;

int n,r,c,res;

void div_conq(int row,int col,int len){
    if(row==r && col==c) {
        cout<<res<<'\n';
        return;
    }
    if(r<row+len && r>=row && c<col+len && c>=col){ // 순서 주의. Z 모양으로 탐색해야 한다.
        div_conq(row,col,len/2);
        div_conq(row,col+len/2,len/2);
        div_conq(row+len/2,col,len/2);
        div_conq(row+len/2,col+len/2,len/2);
    } else{
        res += len*len;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>r>>c; // r: 행, c: 열

    div_conq(0,0, pow(2,n));
}