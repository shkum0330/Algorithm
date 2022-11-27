#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    string answer = "";
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){ // 숫자
            answer += s[i];
        }
        else if(s[i]=='o') { // 1
            answer+='1';
            i+=2;
        }
        else if(s[i]=='z') { //0
            answer+='0';
            i+=3;
        }
        else if(s[i]=='t') { // 2,3
            if(s[i+1]=='w'){
                answer+='2';
                i+=2;
            }
            else if (s[i+1]=='h'){
                answer+='3';
                i+=4;
            }
        }
         else if(s[i]=='f') { // 4,5
            if(s[i+1]=='o'){
                answer+='4';
                i+=3;
            }
            else if (s[i+1]=='i'){
                answer+='5';
                i+=3;
            }
        }
        else if(s[i]=='s') { // 6,7
            if(s[i+1]=='i'){
                answer+='6';
                i+=2;
            }
            else if (s[i+1]=='e'){
                answer+='7';
                i+=4;
            }
        }
        else if(s[i]=='e') { // 8
            answer+='8';
            i+=4;
        }
        else if(s[i]=='n') { // 9
            answer+='9';
            i+=3;
        }
    }
    
    return stoi(answer);
}
