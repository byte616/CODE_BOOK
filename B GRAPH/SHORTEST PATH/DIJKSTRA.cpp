priority_queue<pii,vector<pii>,greater<pii>>pq;
vector<pii>v[MAX_N];
ll dis[MAX_N];
void add_edge(int a,int b,int c){// node : node : dis
    v[a].push_back({b,c});
    v[b].push_back({a,c});
}
ll Dijkstra(int s,int t){// s -> t
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    pq.push({0,s});// dis : node
    while(!pq.empty()){
        pii u=pq.top();
        pq.pop();
        ll a=u.s;
        if(u.f>dis[u.s])continue;
        for(auto k:v[u.s]){
            ll b=k.f,w=k.s;
            if(dis[a]+w<dis[b]){
                dis[b]=dis[a]+w;
                pq.push({dis[b],b});
            }
        }
    }
    if(dis[t]==0x3f)return INF;
    return dis[t];
}