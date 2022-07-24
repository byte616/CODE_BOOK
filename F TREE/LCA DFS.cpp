int n,m,a,b,pa[200005],ans[200005];
vector<int>v[200005];
vector<pii>q[200005];
int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}
void dfs(int x,int pre){
    for(auto i:v[x]){
        dfs(i,x);
    }
    for(auto i:q[x]){
        if(pa[i.f]!=i.f)ans[i.s]=find(i.f);
        else if(x==i.f)ans[i.s]=x;
    }
    pa[x]=pre;
}
main(){
    for(int i=0;i<n;i++){
        cin>>a>>b;// a -> parent
        v[a].push_back(b);// b -> child
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        q[a].push_back({b,i});
        q[b].push_back({a,i});
    }
    for(int i=1;i<=n;i++)pa[i]=i;
    dfs(1,0);
    for(int i=0;i<m;i++)cout<<ans[i]<<'\n';
}