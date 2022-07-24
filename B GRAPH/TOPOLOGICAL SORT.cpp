vector<int>v;// order
void dfs(int x) {
    vis[x]=1;
    for(auto i:v[x]){
        if(vis[i]==1)cycle=1;
        if(!vis[i])dfs(i);
    }
    v.push_back(x);
    vis[x]=2;
}
void topological_sort() {
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    if(cycle)->failed
    else reverse the order and print it
}