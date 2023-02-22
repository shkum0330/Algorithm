import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n, m;
    static StringTokenizer st;
    static List<Camera> carr=new ArrayList<>();
    static int res=99999999;

    static int[][] copyArr(int[][] arr){
        int[][] tmp=new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j]=arr[i][j];
            }
        }
        return tmp;
    }
    static void moveUp(int y,int x,int[][] arr){
        for (int i = y-1; i >=0 ; i--) {
            if(arr[i][x]==6) break;
            if(arr[i][x]==0) arr[i][x]=7;
        }
    }
    static void moveRight(int y,int x,int[][] arr){
        for (int i = x+1; i <m ; i++) {
            if(arr[y][i]==6) break;
            if(arr[y][i]==0) arr[y][i]=7;
        }
    }
    static void moveDown(int y,int x,int[][] arr){
        for (int i = y+1; i < n ; i++) {
            if(arr[i][x]==6) break;
            if(arr[i][x]==0) arr[i][x]=7;
        }
    }
    static void moveLeft(int y,int x,int[][] arr){
        for (int i = x-1; i >=0 ; i--) {
            if(arr[y][i]==6) break;
            if(arr[y][i]==0) arr[y][i]=7;
        }
    }

    static void dfs(int idx,int[][] arr){
        if(idx== carr.size()){
            int cnt=0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(arr[i][j]==0) cnt++;
                }
            }
            res=Math.min(res,cnt);
            return;
        }

        int[][] tmp;
        int y=carr.get(idx).y; int x=carr.get(idx).x;
        if(carr.get(idx).num==1){ // 상하좌우 순
            // 상
            tmp=copyArr(arr);
            moveUp(y,x,tmp);
            dfs(idx+1,tmp);
            // 하
            tmp=copyArr(arr);
            moveDown(y,x,tmp);
            dfs(idx+1,tmp);
            // 좌
            tmp=copyArr(arr);
            moveLeft(y,x,tmp);
            dfs(idx+1,tmp);
            // 우
            tmp=copyArr(arr);
            moveRight(y,x,tmp);
            dfs(idx+1,tmp);
        }
        if(carr.get(idx).num==2){ // 상하-좌우 순
            // 상하
            tmp=copyArr(arr);
            moveUp(y,x,tmp);
            moveDown(y,x,tmp);
            dfs(idx+1,tmp);
            // 좌우
            tmp=copyArr(arr);
            moveRight(y,x,tmp);
            moveLeft(y,x,tmp);
            dfs(idx+1,tmp);

        }
        if(carr.get(idx).num==3){ // 북동-동남-남서-북서 순
            //북동
            tmp=copyArr(arr);
            moveUp(y,x,tmp);
            moveRight(y,x,tmp);
            dfs(idx+1,tmp);
            // 동남
            tmp=copyArr(arr);
            moveRight(y,x,tmp);
            moveDown(y,x,tmp);
            dfs(idx+1,tmp);
            // 남서
            tmp=copyArr(arr);
            moveDown(y,x,tmp);
            moveLeft(y,x,tmp);
            dfs(idx+1,tmp);
            //북서
            tmp=copyArr(arr);
            moveUp(y,x,tmp);
            moveLeft(y,x,tmp);
            dfs(idx+1,tmp);

        }

        if(carr.get(idx).num==4){ // 상하좌우 비우기
            // 북쪽 비우기
            tmp=copyArr(arr);
            moveRight(y,x,tmp);
            moveLeft(y,x,tmp);
            moveDown(y,x,tmp);
            dfs(idx+1,tmp);

            // 동쪽 비우기
            tmp=copyArr(arr);
            moveUp(y,x,tmp);
            moveLeft(y,x,tmp);
            moveDown(y,x,tmp);
            dfs(idx+1,tmp);

            // 남쪽 비우기
            tmp=copyArr(arr);
            moveUp(y,x,tmp);
            moveLeft(y,x,tmp);
            moveRight(y,x,tmp);
            dfs(idx+1,tmp);

            // 서쪽 비우기
            tmp=copyArr(arr);
            moveUp(y,x,tmp);
            moveDown(y,x,tmp);
            moveRight(y,x,tmp);
            dfs(idx+1,tmp);

        }
        if(carr.get(idx).num==5){
            tmp=copyArr(arr);
            moveUp(y,x,tmp);
            moveDown(y,x,tmp);
            moveRight(y,x,tmp);
            moveLeft(y,x,tmp);
            dfs(idx+1,tmp);
        }

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        int [][]arr=new int[n][m];

        for (int i = 0; i < n; i++) {
            st=new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j]=Integer.parseInt(st.nextToken());
                if(arr[i][j] != 0 && arr[i][j] != 6) carr.add(new Camera(i,j,arr[i][j]));
            }
        }

        dfs(0,arr);
        System.out.println(res);
    }
    static class Camera {
        int y,x,num;
        public Camera(int y, int x,int num) {
            this.y = y;
            this.x = x;
            this.num=num;
        }
    }

}