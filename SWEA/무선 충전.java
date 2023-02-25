import java.io.*;
import java.util.*;

public class Solution {
    static int t,m,a;
    static int res;
    static Pair Alocation;
    static Pair Blocation;
    static StringTokenizer st;
    static StringBuilder sb=new StringBuilder();
    static void moving(int person,int direction){
        if(person==1){
            if(direction==1) Alocation.y--;
            if(direction==2) Alocation.x++;
            if(direction==3) Alocation.y++;
            if(direction==4) Alocation.x--;
        }
        if(person==2){
            if(direction==1) Blocation.y--;
            if(direction==2) Blocation.x++;
            if(direction==3) Blocation.y++;
            if(direction==4) Blocation.x--;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            res = 0;
            Alocation=new Pair(1,1);
            Blocation=new Pair(10,10);
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            int moveA[] = new int[m]; // 1번
            int moveB[] = new int[m]; // 2번
            AP ap[] = new AP[a + 1];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; i++) {
                moveA[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; i++) {
                moveB[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 1; i <= a; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                int p = Integer.parseInt(st.nextToken());
                ap[i] = new AP(x, y, c, p);
            }

            for (int i = 0; i < m+1; i++) {

                List<APMap> aList = new ArrayList<>();
                List<APMap> bList = new ArrayList<>();
                for (int j = 1; j <= a; j++) {
                    if (Math.abs(Alocation.x - ap[j].x) + Math.abs(Alocation.y - ap[j].y) <= ap[j].c)
                        aList.add(new APMap(j, ap[j])); // a가 밟고있는 BC
                    if (Math.abs(Blocation.x - ap[j].x) + Math.abs(Blocation.y - ap[j].y) <= ap[j].c)
                        bList.add(new APMap(j, ap[j])); // b가 밟고있는 BC
                }

                int max = 0;
                if (!aList.isEmpty() && !bList.isEmpty()) { // 둘다 무언갈 밟고있다면
                    for (int j = 0; j < aList.size(); j++) {
                        for (int k = 0; k < bList.size(); k++) {
                            int tmp = 0;
                            if (aList.get(j).num == bList.get(k).num) { // 같은 BC를 밟고있다면
                                tmp += aList.get(j).ap.p;
                            } else {
                                tmp += aList.get(j).ap.p + bList.get(k).ap.p;
                            }
                            max = Math.max(tmp, max);
                        }
                    }
                } else if (!aList.isEmpty()) { // a만 무언가 밟고있다면
                    for (int j = 0; j < aList.size(); j++) {
                        int tmp = 0;
                        tmp += aList.get(j).ap.p;
                        max = Math.max(tmp, max);
                    }
                } else if (!bList.isEmpty()) { // b만 무언가 밟고있다면
                    for (int j = 0; j < bList.size(); j++) {
                        int tmp = 0;
                        tmp += bList.get(j).ap.p;
                        max = Math.max(tmp, max);
                    }
                }
                res += max;
//                System.out.println(max);
                if(i==m) break;
                moving(1, moveA[i]);
                moving(2, moveB[i]);
            }
            sb.append("#").append(tc).append(" ").append(res).append("\n");

        }
        System.out.println(sb.toString());
    }
    // 1 2 3 4
    // 1 2 3
    static class Pair{
        int x,y;

        public Pair(int x, int y) {
            this.y = y;
            this.x = x;
        }
    }
    static class AP implements Comparable<AP>{
        int x,y,c,p; // x좌표,y좌표,충전 범위,처리량

        public AP(int x, int y, int c, int p) {
            this.x = x;
            this.y = y;
            this.c = c;
            this.p = p;
        }

        @Override
        public int compareTo(AP o) {
            return Integer.compare(this.p,o.p);
        }
    }
    static class APMap{
        int num; AP ap;

        public APMap(int num, AP ap) {
            this.num = num;
            this.ap = ap;
        }
    }

}