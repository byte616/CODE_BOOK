// O(V^2E)
struct edge{
    int to; ll cap; int rev;
    edge(){}
    edge(int _to, ll _cap, int _rev): to(_to), cap(_cap), rev(_rev){}
};
vector<edge> v[MAX_N];
ll n, m, a, b ,c, s, t;
int level[MAX_N], iter[MAX_N];
void add_edge(int a, int b, ll c){
    v[a].push_back(edge(b, c, v[b].size()));
    v[b].push_back(edge(a, 0, v[a].size() - 1));
}
void BFS(){
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto e : v[cur]){
            if(e.cap > 0 && level[e.to] == -1){
                level[e.to] = level[cur] + 1;
                q.push(e.to);
            }
        }
    }
}
ll dfs(int now, ll flow){ // s -> t
    if(now == t) return flow;
    for(int &i = iter[now]; i < v[now].size(); i++){
        edge &e = v[now][i];
        if(e.cap > 0 && level[e.to] == level[now] + 1){
            ll ret = dfs(e.to, min(flow, e.cap));
            if(ret > 0){
                e.cap -=ret;
                v[e.to][e.rev].cap += ret;
                return ret;
            }
        }
    }
    return 0;
}
ll max_flow(){
    ll ret = 0;
    while(1){
        BFS();
        if(level[t] == -1) break;
        memset(iter, 0, sizeof(iter));
        ll tmp;
        while((tmp = dfs(s, INF)) > 0) ret += tmp;
    }
    return ret;
}
main(){
    s=1,t=n;
    while(m--)add_edge(a,b,c);
    cout<<max_flow();
}


