while(!q.empty()){
    int x=q.front();
    q.pop();
    for(auto i:adj[x]){
        if(!vis[i]){
            vis[i]=1;
            dis[i]=dis[x]+1;
            q.push(i);
            pre[i]=x;
        }
    }
}
void dfs(int x){
    vis[x]=1;
    for(auto i:adj[x])if(!vis[i])dfs(i);
}