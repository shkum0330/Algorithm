#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int j=0;
    bool end = false;
    for(int i=0;i<A.size();i++){
        while(true){
            if(j==B.size()){
                end=true;
                break;
            }
            
            if(A[i]<B[j]) break;
            j++;
        }
        if(end) break;
        answer++;
        j++;
    }
    
    return answer;
}
