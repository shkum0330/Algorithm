import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int n,m;
    static int dy[]={0,-1,0,1};
    static int dx[]={-1,0,1,0};
    static char map[][]=new char[51][51];
    static boolean visited[][][]=new boolean[51][51][1<<6]; // A B C D E F
    static Info start;
    static List<Info> end=new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken());
        m= Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            String s= br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j]=s.charAt(j);
                if(map[i][j]=='0') {
                    start=new Info(i,j);
                    map[i][j]='.';
                }
                if(map[i][j]=='1') {
                    end.add(new Info(i,j));
                }
            }
        }

        System.out.println(bfs(start.y, start.x));
    }
    static int bfs(int y,int x){
        Queue<Info> q=new LinkedList<>();
        q.add(new Info(y,x,0,0));
        visited[y][x][0]=true;
        while (!q.isEmpty()){

            int yy=q.element().y;
            int xx=q.element().x;
            int cnt=q.element().cnt;
            int key=q.element().key;
//            System.out.println(yy+" "+xx);
            q.poll();
            if(map[yy][xx]=='1') return cnt;
            for (int i=0;i<4;i++){
                int ny=yy+dy[i];
                int nx=xx+dx[i];
                if(ny>=n || ny<0 || nx>=m || nx<0) continue;
                if(!visited[ny][nx][key]){
                    if(map[ny][nx]=='1'){ // 도착
                        q.add(new Info(ny,nx,cnt+1,key));
                        visited[ny][nx][key]=true;
                    }
                    if(map[ny][nx]=='.'){ // 빈킨
                        q.add(new Info(ny,nx,cnt+1,key));
                        visited[ny][nx][key]=true;
                    }
                    if(map[ny][nx]>='a' && map[ny][nx]<='f') { // 열쇠
                        int tkey = key | (1 << (map[ny][nx] - 'a'));
                        q.add(new Info(ny, nx, cnt + 1, tkey));
                        visited[ny][nx][tkey] = true;
                    }
                    if(map[ny][nx]>='A' && map[ny][nx]<='F'){ // 문
                        if((key & (1<<(map[ny][nx]-'A'))) != 0){
                            q.add(new Info(ny,nx,cnt+1,key));
                            visited[ny][nx][key]=true;
                        }
                    }
                }
            }
        }
        return -1;
    }

    static class Info {
        int y,x,cnt,key;

        public Info(int y, int x) {
            this.y = y;
            this.x = x;
        }

        public Info(int y, int x, int cnt, int key) {
            this.y = y;
            this.x = x;
            this.cnt = cnt;
            this.key = key;
        }
    }

}