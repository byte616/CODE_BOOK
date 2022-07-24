#define INF 0x3f3f3f3f
struct edge{
    ll to,cap,cost,rev;
    edge(){}
    edge(ll a,ll b,ll c,ll d):to(a),cap(b),cost(c),rev(d){}
};
vector<edge>v[505];
int n,m,k;//n vertices : m edgs : k package
ll flow_cnt,min_cost,dis[MAX_N],pre[MAX_N],pre_id[MAX_N];
//target flow_cnt=k -> ans is min_cost
bool vis[MAX_N];
void add_edge(int a,int b,ll cap,ll cost){
    v[a].push_back(edge(b,cap,cost,v[b].size()));
    v[b].push_back(edge(a,0,-cost,v[a].size()-1));
}
void bellmanford(int s,int t,ll &flow_cnt,ll &min_cost){
    while(1){
        memset(dis,INF,sizeof(dis));
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(s);
        dis[s]=0;
        //use bellmanford to find the shortest path
        while(!q.empty()){
            int u=q.front();
            q.pop();
            vis[u]=0;
            for(int i=0;i<v[u].size();i++){
                edge &e=v[u][i];
                if(e.cap>0&&dis[e.to]>dis[u]+e.cost){
                    dis[e.to]=dis[u]+e.cost;
                    pre[e.to]=u;
                    pre_id[e.to]=i;
                    if(!vis[e.to]){
                        vis[e.to]=1;
                        q.push(e.to);
                    }
                }
            }
        }
        //we can't arrive
        if(dis[t]>=INF)return;
        //find path's min capacity
        ll mi=INF;
        for(int i=t;i!=s;i=pre[i])
            mi=min(mi,v[pre[i]][pre_id[i]].cap);
        //min flow exceed k
        if(flow_cnt+mi>k)mi=k-flow_cnt;
        //renew flow_cnt & min_cost
        flow_cnt+=mi,min_cost+=mi*dis[t];
        //renew the path's capacity
        for(int i=t;i!=s;i=pre[i]){
            edge &e=v[pre[i]][pre_id[i]];
            e.cap-=mi;
            v[e.to][e.rev].cap+=mi;
        }
        if(flow_cnt==k)return;
    }
}
main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        ll a,b,r,c;// a -> b , r=cap, c=cost
        cin>>a>>b>>r>>c;
        add_edge(a,b,r,c);
    }
    bellmanford(1,n,flow_cnt,min_cost);// 1 -> n
    if(flow_cnt==k)cout<<min_cost<<'\n';
    else cout<<-1<<'\n';
}