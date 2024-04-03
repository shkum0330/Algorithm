#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>& v,int num,int k){
    int len=0;
    int max_len=0;
    for(int i=0;i<v.size();i++){
        if(v[i]-num<=0){
            len++;
        }else{
            max_len=max(max_len,len);
            len=0;
        }
    }
    max_len=max(max_len,len);
    if(max_len>=k) return false;
    else return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left=*min_element(stones.begin(),stones.end());
    int right=*max_element(stones.begin(),stones.end());
    
    while(left<=right){
        int mid=(left+right)/2;
        
        if(check(stones,mid,k)){
            left=mid+1;
        }else{
            answer=mid;
            right=mid-1;
        }
    }
    return answer;
}
