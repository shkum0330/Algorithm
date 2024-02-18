#include <string>
#include <vector>
using namespace std;

int dp[1000001];

int solution(int x, int y, int n) {
    int answer = 0;
    
    if(x==y){
        return 0;
    }
    for(int i=x;i<=y;i++){
        if(dp[i]==0 && i>x) continue;
        
        if(i+n<=y){
            if(dp[i+n]==0){
                dp[i+n]=dp[i]+1;
            }else{
                dp[i+n]=min(dp[i+n],dp[i]+1);
            }
        }
        if(i*2<=y){
            if(dp[i*2]==0){
                dp[i*2]=dp[i]+1;
            }else{
                dp[i*2]=min(dp[i*2],dp[i]+1);
            }
        }
        if(i*3<=y){
            if(dp[i*3]==0){
                dp[i*3]=dp[i]+1;
            }else{
                dp[i*3]=min(dp[i*3],dp[i]+1);
            }
        }
    }

    if(dp[y] == 0)answer=-1;
    else answer=dp[y];
    return answer;
}
