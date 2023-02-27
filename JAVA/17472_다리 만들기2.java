import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static int n,m,res;
    static int num=1;
    static int parent[]=new int[7];
    static int map[][]=new int[101][101];
    static boolean visited[][]=new boolean[101][101];
    static int dist[][]=new int[7][7];
    static List<Edge> edge=new ArrayList<>();
    static int dx[]={-1,0,1,0};
    static int dy[]={0,-1,0,1};
    static class Edge implements Comparable<Edge>{
        int s,e,c;

        public Edge(int s, int e, int c) {
            this.s = s;
            this.e = e;
            this.c = c;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.c,o.c);
        }
    }
    static void dfs(int y,int x){
        map[y][x]=num;
        for (int i = 0; i < 4; i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=n || ny<0 || nx>m || nx<0) continue;
            if(!visited[ny][nx] && map[ny][nx]==1) {
                visited[ny][nx]=true;
                dfs(ny,nx);

            }
        }
    }
    static int find(int a){
        if(parent[a]==a) return a;
        else return parent[a]=find(parent[a]);
    }
    static void merge(int a,int b){
        int aRoot=find(a); int bRoot= find(b);
        parent[bRoot]=aRoot;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken());
        m= Integer.parseInt(st.nextToken());
        for (int i = 1; i <=6; i++) {
            parent[i]=i;
        }
        for (int i = 0; i < n; i++) {
            st=new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j]= Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!visited[i][j] && map[i][j]==1){
                    visited[i][j]=true;
                    dfs(i,j);
                    num++;
                }
            }
        }

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                dist[i][j]=9999; // i번 섬에서 j번 섬까지 거리
            }
        }

        for (int i = 0; i<n ; i++) { // 섬간 거리 계산
            for (int j = 0; j < m; j++) {
                if(map[i][j] != 0) {
                    for (int k = 0; k < 4; k++) {
                        int cnt=0;
                        int y=i; int x=j;
                        while(true){
                            y+=dy[k];
                            x+=dx[k];
                            if(y>=n || y<0 || x>=m || x<0) break; // 지도 범위 벗어나면 break
                            if(map[y][x]==map[i][j]) break; // 같은 섬과 충돌시 break
                            if(map[y][x]==0){ // 0이면 계속 전진
                                cnt++;
                                continue;
                            }
                            if(map[y][x]!=map[i][j] && map[y][x] != 0){ // 다른 섬에 도달
                                if(cnt>1) {
                                    dist[map[i][j]][map[y][x]]=Math.min(dist[map[i][j]][map[y][x]],cnt);
                                    dist[map[y][x]][map[i][j]]=Math.min(dist[map[i][j]][map[y][x]],cnt);
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }

        num--;
        for (int i = 1; i <= num-1; i++) {
            for (int j = i+1; j <=num ; j++) {
                if(dist[i][j] != 9999){
                    edge.add(new Edge(i,j,dist[i][j]));
                }

            }
        }

        int cnt=0;
        Collections.sort(edge);
        for(int i = 0; i< edge.size(); i++){
            if(find(edge.get(i).s) != find(edge.get(i).e)){
                merge(edge.get(i).s,edge.get(i).e);
                res += edge.get(i).c;
                cnt++;
            }
        }

        if(cnt!=num-1) System.out.println(-1);
        else System.out.println(res);
    }
}