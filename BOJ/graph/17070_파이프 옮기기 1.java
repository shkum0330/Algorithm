import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int map[][]=new int[34][34];
    static int dy[]={0,1,1};
    static int dx[]={1,0,1};
    static int n,res;
    static void dfs(int y,int x,int prev){
//        System.out.println(y+" "+x);
        if(y==n && x==n){
            res++;
            return;
        }
        for (int i=0;i<3;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>n || ny <= 0 || nx>n || nx<=0) continue;
            if(map[ny][nx]==0){
                if(i==2 && map[y+1][x] == 0 && map[y][x+1]==0) dfs(ny,nx,i);
                if((i==1 || i==0) && (prev == i || prev==2)) dfs(ny,nx,i);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        n= Integer.parseInt(br.readLine());
        for (int i = 1; i <= n; i++) {
            st=new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                map[i][j]= Integer.parseInt(st.nextToken());
            }
        }

        dfs(1,2,0);

        System.out.println(res);
    }

}