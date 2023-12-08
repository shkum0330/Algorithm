import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int n,d,k,c;
    static int arr[]=new int[3001];
    static ArrayList<Integer> sushi=new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken());
        d= Integer.parseInt(st.nextToken());
        k= Integer.parseInt(st.nextToken());
        c= Integer.parseInt(st.nextToken());
        arr[c]=1;
        for (int i = 0; i < n; i++) {
            int tmp= Integer.parseInt(br.readLine());
            sushi.add(tmp);
        }
        int res=0; int cnt=0;
        for (int i = 0; i < k; i++) {
            arr[sushi.get(i)]++;
        }
        for (int i = 1; i <= d; i++) {
            if(arr[i] != 0) cnt++;
        }

        int start=0; int end=k-1;
        while (true){
            arr[sushi.get(start)]--;
            if(arr[sushi.get(start)]==0) cnt--;
            start++;
            if(start==n) break;
            end++;
            if(end==n) end=0;
            if(arr[sushi.get(end)]==0) cnt++;
            arr[sushi.get(end)]++;
            res=Math.max(res,cnt);
        }
        System.out.println(res);
    }
}

