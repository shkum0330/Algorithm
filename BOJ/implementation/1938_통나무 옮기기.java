import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static char map[][];
    static int dist[][][];
    static boolean visited[][][];
    static int dy[]= {-1,0,1,0};
    static int dx[]= {0,-1,0,1};
    static Pair b;
    static Pair e;
    static void bfs(int y,int x,int status) {
        Queue<Pair> q=new LinkedList<>();
        q.add(new Pair(y,x,status));
        visited[y][x][status]=true;

        while(!q.isEmpty()) {

            int yy=q.element().getY();
            int xx=q.element().getX();

            int sstatus=q.element().getStatus();

            if(yy==e.getY() && xx==e.getX() && sstatus==e.getStatus()) return;
            q.poll();
            for(int i=0;i<4;i++) {
                int ny=yy+dy[i];
                int nx=xx+dx[i];
                if(sstatus==1) { // 서있는 상태
                    if(ny+1>=n || ny-1<0 || nx>=n || nx<0 ) continue;
                    if(!visited[ny][nx][1] && map[ny][nx]!='1' && map[ny-1][nx]!='1' && map[ny+1][nx]!='1') {
                        q.add(new Pair(ny,nx,1));
                        dist[ny][nx][sstatus]=dist[yy][xx][sstatus]+1;
                        visited[ny][nx][1]=true;
                    }
                }else { // 누워있는 상태
                    if(ny>=n || ny<0 || nx+1>=n || nx-1<0 ) continue;
                    if(!visited[ny][nx][0] && map[ny][nx]!='1' && map[ny][nx-1]!='1' && map[ny][nx+1]!='1') {
                        q.add(new Pair(ny,nx,0));
                        dist[ny][nx][sstatus]=dist[yy][xx][sstatus]+1;
                        visited[ny][nx][0]=true;
                    }
                }
            }
            boolean flag=true;
            if(yy>=1 && yy<n-1 && xx>=1 && xx<n-1) {
                for(int i=yy-1;i<=yy+1;i++) {
                    for(int j=xx-1;j<=xx+1;j++) {
                        if(map[i][j]=='1') flag=false;
                    }
                }
            } else flag=false;
            if(flag) {
                if(sstatus==1 && !visited[yy][xx][0]) {
                    sstatus=0;
                    q.add(new Pair(yy,xx,sstatus));
                    dist[yy][xx][sstatus]=dist[yy][xx][1]+1;
                    visited[yy][xx][sstatus]=true;
                }
                else if(sstatus==0 && !visited[yy][xx][1]){
                    sstatus=1;
                    q.add(new Pair(yy,xx,sstatus));
                    dist[yy][xx][sstatus]=dist[yy][xx][0]+1;
                    visited[yy][xx][sstatus]=true;
                }
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        map=new char[n+1][n+1];
        dist=new int[n+1][n+1][2];
        visited=new boolean[n+1][n+1][2];
        int bcnt=0; int ecnt=0;
        for (int i = 0; i < n; i++) {
            String s; s=br.readLine();
            for (int j = 0; j < n; j++) {
                map[i][j]=s.charAt(j);
                if(map[i][j]=='B') bcnt++;
                if(map[i][j]=='E') ecnt++;
                if(bcnt==2) {
                    if(i-1>=0 && map[i-1][j]=='B') { // 세로로 서있는 상태
                        b=new Pair(i,j,1);
                    }else { // 가로로 누워있는 상태
                        b=new Pair(i,j,0);
                    }
                    bcnt++;
                }
                if(ecnt==2){
                    if(i-1>=0 && map[i-1][j]=='E') { // 세로로 서있는 상태
                        e=new Pair(i,j,1);
                    }else { // 가로로 누워있는 상태
                        e=new Pair(i,j,0);
                    }
                    ecnt++;
                }
            }
        }
        bfs(b.getY(),b.getX(),b.status);
        System.out.println(dist[e.getY()][e.getX()][e.getStatus()]);
    }
    static class Pair{
        int y,x,status; // status가 1이면 세로, 0이면 가로

        public Pair(int y, int x,int status) {
            super();
            this.y = y;
            this.x = x;
            this.status=status;
        }

        public int getY() {
            return y;
        }

        public void setY(int y) {
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public void setX(int x) {
            this.x = x;
        }

        public int getStatus() {
            return status;
        }

        public void setStatus(int status) {
            this.status = status;
        }


    }
}
