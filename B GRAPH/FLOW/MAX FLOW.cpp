ll n,m,a,b,c,s,n;
bool vis[MAX_N];
struct edge{
    int to;ll cap;int rev;
    edge(){};
    edge(int _a,ll _b,int _c):to(_a),cap(_b),rev(_c){}
}
vector<edge>v[MAX_N];
ll dfs(int now,ll flow){// s -> t
    vis[now]=1;
    if(now==t)return flow;
    for(int i=0;i<v[now].size();i++){
        edge &e=v[now][i];
        if(e.cap>0&&!vis[e.to]){
            ll ret=dfs(e.to,min(flow,e.cap));
            if(ret>0){
                e.cap-=ret;
                v[e.to][e.rev].cap+=ret;
                return ret;
            }
        }
    }
    return 0;
}
ll max_flow(){
    ll ret=0,tmp=0;
    while((tmp=dfs(1,INF))>0){//INF->1e18
        ret+=tmp;
        memset(vis,0,sizeof(vis));
    }
    return ret;
}
void add_edge(int a,int b,int c){
    v[a].push_back(edge(b,c,v[b].size()));
    v[b].push_back(edge(a,0,v[a].size()-1));
}
main(){
    s=1,t=n;
    while(m--)add_edge(a,b,c);
    cout<<max_flow();
}