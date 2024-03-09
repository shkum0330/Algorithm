//다익스트라
int dijkstra(int start,int end){
    for (int i = 1; i <= n; ++i) {
        dist[i]=INF;
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[start]=0;
    pq.push({0,start});
    while (!pq.empty()){
        int curr=pq.top().second; int currd=pq.top().first;
        pq.pop();
        for (auto& k:d[curr]) {
            int next=k.first; int nextd=k.second;
            if(dist[next]>currd+nextd){
                dist[next]=currd+nextd;
                pq.push({dist[next],next});
            }
        }
    }
    return dist[end];
}

//벨만-포드
void bellman_Ford(){
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            if(dist[e[j].e]>dist[e[j].s]+e[j].w && dist[e[j].s] != INF) dist[e[j].e]=dist[e[j].s]+e[j].w;
        }
    }
}

//플로이드-워셜
void floyd_Warshall(){
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <=n; ++j) {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
