import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    static int t,n,res;
    static char map[][];
    static boolean visited[][];
    static int dy[]={-1,-1,-1,0,0,1,1,1};
    static int dx[]={-1,0,1,-1,1,-1,0,1};
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;

    static void bfs(int y,int x){
        res++;
        Queue<Point> q=new LinkedList<>();
        q.add(new Point(y,x));
        while (!q.isEmpty()){
            int ty=q.element().y;
            int tx=q.element().x;
            q.poll();
            visited[ty][tx]=true;
            for (int i = 0; i < 8; i++) {
                int ny=ty+dy[i];
                int nx=tx+dx[i];
                if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                if(map[ny][nx] != '*' && !visited[ny][nx]) {
                    visited[ny][nx]=true;
                    if(map[ny][nx]=='0') q.add(new Point(ny,nx));
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t= Integer.parseInt(br.readLine());
        for(int tc=1;tc<=t;tc++){
            res=0;
            n= Integer.parseInt(br.readLine());
            map=new char[301][301];
            visited=new boolean[301][301];
            for (int i = 0; i < n; i++) {
                String s; s=br.readLine();
                for (int j = 0; j < n; j++) {
                    map[i][j]=s.charAt(j);
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int cnt=0;
                    if(map[i][j]=='.'){
                        for (int k = 0; k < 8; k++) {
                            int ny=i+dy[k];
                            int nx=j+dx[k];
                            if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                            if(map[ny][nx]=='*'){
                                cnt++;
                            }

                        }
                        map[i][j]=Character.forDigit(cnt,10);
                    }

                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(!visited[i][j] && map[i][j] == '0') bfs(i,j);
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(!visited[i][j] && map[i][j] != '*') res++;
                }
            }
//            for (int i = 0; i < n; i++) {
//                for (int j = 0; j < n; j++) {
//                    System.out.print(map[i][j]+" ");
//                }
//                System.out.println();
//            }
            sb.append("#").append(tc).append(" ").append(res).append("\n");

        }
        System.out.println(sb);
    }
    static class Point{
        int y,x;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}