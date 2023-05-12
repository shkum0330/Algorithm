import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        double answer = 0;
        List<String> arr1=new ArrayList<>();
        List<String> arr2=new ArrayList<>();
        List<String> union=new ArrayList<>();
        List<String> intersection=new ArrayList<>();
        int cnt=0; String tmp="";

        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        for(int i=0;i<str1.length();i++){
            if(!(str1.charAt(i)>='a' && str1.charAt(i)<='z')){
                tmp="";
                cnt=0;
                continue;
            }
            cnt++;
            tmp+=str1.charAt(i);
            if(cnt==2){
                arr1.add(tmp);
                tmp="";
                cnt=0;
                i--;
            }
        }
        tmp=""; cnt=0;
        for(int i=0;i<str2.length();i++){
            if(!(str2.charAt(i)>='a' && str2.charAt(i)<='z')){
                tmp="";
                cnt=0;
                continue;
            }
            cnt++;
            tmp+=str2.charAt(i);
            if(cnt==2){
                arr2.add(tmp);
                tmp="";
                cnt=0;
                i--;
            }
        }

        for(String s:arr1){
            if(arr2.remove(s)){ // arrayList 요소 제거
                intersection.add(s);
            }
            union.add(s);
        }
        for(String s:arr2){
            union.add(s);
        }

        if(union.size() == 0) {
            answer = 1;
        } else {
            answer = (double)intersection.size() / (double)union.size();
        }

        return (int)(answer*65536);
    }
}