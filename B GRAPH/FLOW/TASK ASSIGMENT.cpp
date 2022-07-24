//There n jobs and n employees.
//We know for each employee the cost of carrying out each task.
//Every employee should be signed to exactly one task. 
//What is the minimum total cost.
//cap -> 1
bool bellmanford(int s,int t){
    // bellman_ford part is like MCMF
    if(dis[t]>=INF)return 0;
    flow_cnt++,min_cost+=dis[t];
    for(int i=t;i!=s;i=pre[i]){
        edge &e=v[pre[i]][pre_id[i]];
        e.cap-=1;
        v[e.to][e.rev].cap+=1;
    }
    return 1;
}
void add_edge(int a,int b,ll cost){
    v[a].push_back(edge(b,1,cost,v[b].size()));
    v[b].push_back(edge(a,0,-cost,v[a].size()-1));
}
main(){
    cin>>n;
    //build the graph seperate into two side (1~n : n+1~2n)
    // left: employee, right: task
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            add_edge(i,j+n,x);
        }
    }
    //left side (1~n) connect s, right side (n+1~2n) connect t
    int s=0,t=2*n+1;
    for(int i=1;i<=n;i++){
        add_edge(s,i,0);
        add_edge(i+n,t,0);
    }
    while(flow_cnt<n&&bellmanford(s,t));
    cout<<min_cost<<'\n';
}