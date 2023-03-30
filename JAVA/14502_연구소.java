import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int map[][]=new int[9][9];
    static int tmp[][]=new int[9][9];
    static int dx[]={-1,0,1,0};
    static int dy[]={0,-1,0,1};
    static int n,m,res;
    static boolean combiVisited[]=new boolean[65];
    static boolean visited[][]=new boolean[9][9];
    static List<Point> blank=new ArrayList<>();
    static List<Point> virus=new ArrayList<>();
    static List<Point> wall=new ArrayList<>();
    public static void bfs(Point v){
        Queue<Point> q=new LinkedList<>();
        q.add(v);
        visited[v.y][v.x]=true;
        while (!q.isEmpty()){
            int y=q.element().y;
            int x=q.element().x;
            q.poll();
            for (int i = 0; i < 4; i++) {
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(ny>=n || ny<0 || nx>=m || nx<0) continue;
                if(!visited[ny][nx] && tmp[ny][nx]==0){
                    q.add(new Point(ny,nx));
                    tmp[ny][nx]=2;
                }
            }
        }
    }
    public static int countAndInit(){
        int count=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(tmp[i][j]==0) count++;
                visited[i][j]=false;
            }
        }
//        System.out.println(count);
        return count;
    }
    public static void copyArr(){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j]=map[i][j];
            }
        }
    }
    //    public static void printArr(){
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                System.out.print(tmp[i][j]+" ");
//            }
//            System.out.println();
//        }
//    }
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken()); m= Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st=new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j]= Integer.parseInt(st.nextToken());
                if(map[i][j]==0) blank.add(new Point(i,j));
                if(map[i][j]==2) virus.add(new Point(i,j));
            }
        }
        int size= n*m;
        for (int i = 0; i < blank.size()-2; i++) {
            for (int j = i+1; j < blank.size()-1; j++) {
                for (int k = j+1; k < blank.size(); k++) {
                    copyArr();
                    tmp[blank.get(i).y][blank.get(i).x]=1;
                    tmp[blank.get(j).y][blank.get(j).x]=1;
                    tmp[blank.get(k).y][blank.get(k).x]=1;
                    for (int l = 0; l < virus.size(); l++) {
                        bfs(virus.get(l));
                    }
                    res=Math.max(countAndInit(),res);

                }

            }
        }
        System.out.println(res);
    }
    static class Point{
        int y,x;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public String toString() {
            return "Point{" +
                    "y=" + y +
                    ", x=" + x +
                    '}';
        }
    }
}