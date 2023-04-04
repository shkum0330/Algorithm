import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int dy[]={0,-1,0,1};
    static int dx[]={-1,0,1,0};
    static int map[][];
    static boolean visited[][];
    static int landDist[][];
    static int dist[][];
    static ArrayList<Pair> land[];
    static int landNum;
    static int n,res;
    static void bfs(int y,int x){
        visited[y][x]=true;
        map[y][x]=landNum;

        land[landNum].add(new Pair(y,x));
        Queue<Pair> q=new LinkedList<>();
        q.add(new Pair(y,x));
        while (!q.isEmpty()){
            int yy=q.element().first;
            int xx=q.element().second;
            q.poll();
            for (int i = 0; i < 4; i++) {
                int ny=yy+dy[i];
                int nx=xx+dx[i];
                if(ny>=n || ny<0 || nx>=n || nx<0) continue;
                if(!visited[ny][nx] && map[ny][nx]==1){
                    visited[ny][nx]=true;
                    map[ny][nx]=landNum;
                    land[landNum].add(new Pair(ny,nx));
                    q.add(new Pair(ny,nx));
                }
            }
        }
    }
    static void calcDist(int y,int x,int target){
        Queue<Pair> q=new LinkedList<>();
        q.add(new Pair(y,x));
        while (!q.isEmpty()){
            int yy=q.element().first;
            int xx=q.element().second;

            if(map[yy][xx]==target){
                System.out.println(yy+" "+xx+" "+target);
                System.out.println(dist[yy][xx]);
                res=Math.min(res,dist[yy][xx]);
            }
            q.poll();
            for (int i = 0; i < 4; i++) {
                int ny=yy+dy[i];
                int nx=xx+dx[i];
                if(ny>=n || ny<0 || nx>=n || nx<0) continue;
                if(!(ny == y && nx == x) && dist[ny][nx]==0 ){
                    dist[ny][nx]=dist[y][x]+1;
                    q.add(new Pair(ny,nx));
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n= Integer.parseInt(br.readLine());
        map=new int[n+1][n+1];
        visited=new boolean[n+1][n+1];
        landDist=new int[n+1][n+1];
        land=new ArrayList[(n+1)*(n+1)]; // 섬에 속한 정점들 저장하는 변수
        land[0]=new ArrayList(); // dummy
        res=987654321;
        for (int i = 0; i < n; i++) {
            st=new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j]= Integer.parseInt(st.nextToken());
            }
        }
        landNum=1; // 1번 섬부터 지정
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(!visited[i][j] && map[i][j]==1){ // bfs로 정점마다 섬의 번호를 지정
                    land[landNum]=new ArrayList();
                    bfs(i,j);
                    landNum++;
                }
            }
        }
        landNum--; // 마지막에 landNum에 1이 더해지므로 1을 뺀다.
        for (int i = 1; i <= landNum-1; i++) { // 시작섬
            for (int j = i+1; j <=landNum ; j++) { // 도착섬
                for (int k = 0; k < land[i].size(); k++) { // 시작-도착섬에 속하는 정점끼리
                    for (int l = 0; l < land[j].size(); l++) { // 맨해튼 거리의 최솟값을 구함
                        res=Math.min(res,Math.abs(land[i].get(k).first-land[j].get(l).first)+Math.abs(land[i].get(k).second-land[j].get(l).second));
                    }
                }
            }
        }
        System.out.println(res-1); // 격자 구조상 1이 더해지므로 빼준다.
    }

    static class Pair{
        int first,second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}