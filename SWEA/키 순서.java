import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int t,n,m,res;
    static int e[][];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t= Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            res=0;
            n=Integer.parseInt(br.readLine()); m=Integer.parseInt(br.readLine());
            e=new int[n+1][n+1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    e[i][j]=987654321;
                }
            }
            for (int i = 0; i < m; i++) {
                st=new StringTokenizer(br.readLine());
                int start= Integer.parseInt(st.nextToken());
                int end= Integer.parseInt(st.nextToken());
                e[start][end]=1;
            }

            for(int k=1; k<=n; k++)
                for(int i=1; i<=n; i++)
                    for(int j=1; j<=n; j++)
                        if (e[i][j]>e[i][k]+e[k][j])  e[i][j] = e[i][k]+e[k][j]; // 플로이드-워셜로 모든 정점간 최단거리를 구한다. 즉 어떤 정점으로 갈 수 있는지 알아본다.

            for (int i = 1; i <= n; i++) { // 나머지 모든 정점에 대해 들어오는 경로와 들어가는 경로가 없으면
                boolean flag=true; // flag를 false로 만든다.
                for (int j = 1; j <= n; j++) {
                    if(i==j) continue;
                    if(e[i][j] == 987654321 && e[j][i] == 987654321) flag=false;
                }
                if(flag) {
                    res++;
                }
            }
            sb.append("#").append(tc).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
}