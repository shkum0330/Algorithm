import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n, m, k,sum;
    static int res=1999999999;
    static StringTokenizer st;
    static int arr[][]=new int[51][51];
    static int tarr[][]=new int[51][51];
    static Range calc[];
    static ArrayList<Range> output=new ArrayList<>();
    static boolean visited[];
    static void rotate(int rs,int cs,int re,int ce){

        int count=Math.min(re-rs+1,ce-cs+1)/2;

        for (int k=0;k<count;k++){
            int tmp=tarr[rs][ce];
            for (int i=ce;i>cs;i--){
                tarr[rs][i]=tarr[rs][i-1];
            }
            for (int i=rs;i<re;i++){
                tarr[i][cs]=tarr[i+1][cs];
            }
            for (int i=cs;i<ce;i++){
                tarr[re][i]=tarr[re][i+1];
            }
            for (int i=re;i>rs+1;i--){
                tarr[i][ce]=tarr[i-1][ce];
            }
            tarr[rs+1][ce]=tmp;

            rs++; cs++; re--; ce--;
        }
    }
    static void perm(int cnt){
        sum=0;
        if(cnt==k) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    tarr[i][j] = arr[i][j];
                }
            }
            for (Range r:output){
                rotate(r.getR()-r.getS(),r.getC()-r.getS(),r.getR()+r.getS(),r.getC()+r.getS());
            }

            for (int i=1;i<=n;i++){
                int tmp=0;
                for (int j=0;j<=m;j++){
                    tmp+=tarr[i][j];
                }

                res=Math.min(tmp,res);
            }
            return;
        }
        for (int i=0;i<calc.length;i++){
            if(visited[i]) continue;
            visited[i]=true;
            output.add(calc[i]);
            perm(cnt+1);
            output.remove(output.size()-1);
            visited[i]=false;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken());
        m= Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        calc=new Range[k];
        visited=new boolean[k];
        for (int i = 0; i < k; i++) {
            st=new StringTokenizer(br.readLine());
            int r,c,s;
            r= Integer.parseInt(st.nextToken());
            c= Integer.parseInt(st.nextToken());
            s= Integer.parseInt(st.nextToken());
            calc[i]=new Range(r,c,s);
        }
        perm(0);
        System.out.println(res);
    }

    static class Range{
        int r,c,s;
        public Range(int r, int c, int s) {
            this.r = r;
            this.c = c;
            this.s = s;
        }
        public int getR() {
            return r;
        }

        public int getC() {
            return c;
        }

        public int getS() {
            return s;
        }

        @Override
        public String toString() {
            return "Range{" +
                    "r=" + r +
                    ", c=" + c +
                    ", s=" + s +
                    '}';
        }
    }
}