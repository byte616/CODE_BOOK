ll n,x,y,sz[200005],dis[200005];//sz-->subtree
vector<int>v[200005];
void dfs_sz(int x,int pre,int d){
    dis[1]+=d;
    for(auto i:v[x]){
        if(i==pre)continue;
        dfs_sz(i,x,d+1);
        sz[x]+=sz[i];
    }
    sz[x]++;
}
void dfs(int x,int pre){
    for(auto i:v[x]){
        if(i==pre)continue;
        dis[i]=dis[x]+(n-sz[i])-sz[i];//n-sz[i]-->+1 : sz[i]-->-1
        dfs(i,x);
    }
}
main(){
    add_edge();// 雙向
    dfs_sz(1,0,0);
    dfs(1,0);
    for(int i=1;i<=n;i++)cout<<dis[i]<<"\n";
}