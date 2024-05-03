import java.util.*;

class Solution {
    static boolean visited[]=new boolean[50000001];
    static boolean flag;
    static ArrayList<ArrayList<String>> res=new ArrayList<>();
    public String[] solution(String[][] tickets) {
        String[] answer = {};
        Arrays.sort(tickets,(a,b)->a[0].compareTo(b[0]));

        ArrayList<String> list=new ArrayList<>();
        list.add("ICN");
        dfs(0,"ICN",list,tickets);

        Collections.sort(res,new Comparator<ArrayList<String>>(){
            @Override
            public int compare(ArrayList<String> a,ArrayList<String> b){

                return String.join("",a).compareTo(String.join("", b));
            }
        });

        answer=res.get(0).toArray(new String[0]);

        return answer;
    }

    static void dfs(int cnt,String start,ArrayList<String> list,String[][] tickets){
        if(cnt==tickets.length){
            res.add(new ArrayList<>(list));
            return;
        }

        for(int i=0;i<tickets.length;i++){
            if(!visited[i] && start.equals(tickets[i][0])){
                visited[i]=true;
                list.add(tickets[i][1]);
                dfs(cnt+1,tickets[i][1],list,tickets);
                list.remove(list.size()-1);
                visited[i]=false;
            }

        }
    }
}