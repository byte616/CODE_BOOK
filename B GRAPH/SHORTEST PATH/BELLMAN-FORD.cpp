struct edge {
    int a,b;
    ll w;
}p[MAX_M];
ll dis[MAX_N];    
int n,m;// n vertices, m edges
ll Bellman_Ford(int s,int t){// s -> t
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    for (int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(dis[p[j].a]+p[j].w<dis[p[j].b]){
                dis[p[j].b]=dis[p[j].a]+p[j].w;
                if(i==n){
                   if(p[j].b==t)return INF;
                   //didn't exist shortest path
                }
            }
        }
    }
    return dis[t];
}