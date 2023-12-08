import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int t,n,x,res;
    static int map[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        res=0;
        st=new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken()); x= Integer.parseInt(st.nextToken());
        map=new int[n+x+1][n+x+1];
        for (int i = 0; i < n; i++) {
            st=new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j]= Integer.parseInt(st.nextToken());
            }
        }
        if(x==1){ // x가 1일때 따로 처리
            boolean flag;
            for (int i = 0; i < n; i++) {
                flag=true;
                for (int j = 1; j < n; j++) {
                    if(Math.abs(map[i][j]-map[i][j-1])>1){
                        flag=false;
                        break;
                    }
                }
                for (int j = 1; j < n-1; j++) {
                    if(map[i][j-1]==map[i][j+1] && map[i][j-1] > map[i][j]) {
                        flag=false;
                        break;
                    }
                }
                if(flag){

                    res++;
                }
            }
            for (int i = 0; i < n; i++) {
                flag=true;
                for (int j = 1; j < n; j++) {
                    if(Math.abs(map[j][i]-map[j-1][i])>1){
                        flag=false;
                        break;
                    }
                }
                for (int j = 1; j < n-1; j++) {
                    if(map[j-1][i]==map[j+1][i] && map[j-1][i] > map[j][i]) {
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    res++;
                }
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                boolean canConstruct = false;
                boolean flag = true;
                for (int j = 1; j < n; j++) {
                    if ((Math.abs(map[i][j] - map[i][j - 1])) > 1) { // 높이 차이가 1보다 크면 건설 못함
                        flag = false;
                        break;
                    }
                    if (map[i][j] == map[i][j - 1]) cnt++;
                    if (cnt == x) {
                        canConstruct = true; // x만큼 평지를 전진하여 경사로를 건설할 수 있는 상태
                    }
                    if (map[i][j] - map[i][j - 1] == 1) { // 낮은곳에서 높은곳으로
                        if (canConstruct) {
                            cnt = 1;
                            canConstruct = false;
                        } else break;
                    } else if (map[i][j] - map[i][j - 1] == -1) { // 높은곳에서 낮은곳으로
                        boolean isSameHeight = true;
                        for (int k = j; k < j + x - 1; k++) {
                            if (map[i][k] != map[i][k + 1]) isSameHeight = false;
                        }
                        if (!isSameHeight) {
                            flag = false;
                            break;
                        } else {
                            cnt = 0;
                            j += (x - 1);
                            canConstruct = false;
                            if (j >= n) break;
                            if (j < n - 1) continue;
                        }
                    }
                    if (j == n - 1) { // 끝까지 도착
                        res++;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                boolean canConstruct = false;
                boolean flag = true;
                for (int j = 1; j < n; j++) {
                    if ((Math.abs(map[j][i] - map[j - 1][i])) > 1) { // 높이 차이가 1보다 크면 건설 못함
                        flag = false;
                        break;
                    }
                    if (map[j][i] == map[j - 1][i]) cnt++;
                    if (cnt == x) {
                        canConstruct = true; // x만큼 평지를 전진하여 경사로를 건설할 수 있는 상태
                    }
                    if (map[j][i] - map[j - 1][i] == 1) { // 낮은곳에서 높은곳으로
                        if (canConstruct) {
                            cnt = 1;
                            canConstruct = false;
                        } else break;
                    } else if (map[j][i] - map[j - 1][i] == -1) { // 높은곳에서 낮은곳으로
                        boolean isSameHeight = true;
                        for (int k = j; k < j + x - 1; k++) {
                            if (map[k][i] != map[k + 1][i]) isSameHeight = false;
                        }
                        if (!isSameHeight) {
                            flag = false;
                            break;
                        } else {
                            cnt = 0;
                            canConstruct = false;
                            j += (x - 1);

                            if (j >= n) break;
                            if (j < n - 1) continue;

                        }
                    }
                    if (j == n - 1) { // 끝까지 도착
                        res++;
                    }
                }
            }
        }
        System.out.println(res);
    }
}