import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static char map[][];
    static int dy[]={-1,0,1,0};
    static int dx[]={0,-1,0,1};
    static List<Pair> bomb=new ArrayList<>();
    static int r,c,n;
    public static void setBomb(){
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                map[i][j]='O';
            }
        }
    }
    public static void bomb(){
        for(Pair p:bomb){
            int y=p.y; int x=p.x;
            map[y][x]='.';
            for (int i = 0; i < 4; i++) {
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(ny>=r || ny<0 || nx>=c || nx<0) continue;
                map[ny][nx]='.';
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer(br.readLine());
        r= Integer.parseInt(st.nextToken());
        c= Integer.parseInt(st.nextToken());
        n= Integer.parseInt(st.nextToken());
        map=new char[r+1][c+1];
        for (int i = 0; i < r; i++) {
            String s=br.readLine();
            for (int j = 0; j < c; j++) {
                map[i][j]=s.charAt(j);
                if(map[i][j]=='O'){
                    bomb.add(new Pair(i,j));
                }
            }
        }
        if(n==1){
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    sb.append(map[i][j]);
                }
                sb.append("\n");
            }
        }
        if(n%2==0){
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    sb.append("O");
                }
                sb.append("\n");
            }
        }
        if(n>=3) {
            n %= 4;
            if (n == 3) {
                setBomb();
                bomb();
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        sb.append(map[i][j]);
                    }
                    sb.append("\n");
                }
            }
            if (n == 1) {
                setBomb();
                bomb();
                bomb = new ArrayList<>();
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (map[i][j] == 'O') {
                            bomb.add(new Pair(i, j));
                        }
                    }
                }
                setBomb();
                bomb();
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        sb.append(map[i][j]);
                    }
                    sb.append("\n");
                }
            }
        }
        System.out.println(sb);

    }
    static class Pair{
        int y,x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}