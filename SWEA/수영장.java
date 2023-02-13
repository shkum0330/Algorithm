import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    static int t;
    static StringTokenizer st;
    static int price[]=new int[4];
    static int plan[]=new int[13];
    static int res=199999999;
    static void dfs(int month,int ticket,int total){
        if(month>12){
            res=Math.min(total,res);
            return;
        }
        if(ticket==0){ // 1일권
            total += (plan[month]*price[0]);
            dfs(month+1, 0,total);
            dfs(month+1, 1,total);
            dfs(month+1, 2,total);
        }else if(ticket==1){ // 1달권
            total += price[1];
            dfs(month+1, 0,total);
            dfs(month+1, 1,total);
            dfs(month+1, 2,total);
        }else if(ticket==2){ // 3달권
            total += price[2];
            dfs(month+3, 0,total);
            dfs(month+3, 1,total);
            dfs(month+3, 2,total);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t= Integer.parseInt(br.readLine());
        for(int k=1;k<=t;k++){
            res=199999999;
            st=new StringTokenizer(br.readLine());
            for (int i=0;i<4;i++){
                price[i]= Integer.parseInt(st.nextToken());
            }
            st=new StringTokenizer(br.readLine());
            for (int i=1;i<=12;i++){
                plan[i]= Integer.parseInt(st.nextToken());
            }

            dfs(1, 0,0);
            dfs(1, 1,0);
            dfs(1, 2,0);
            System.out.println("#"+k+" "+Math.min(price[3],res));

        }
    }
}