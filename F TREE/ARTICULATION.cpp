int dfn[200005],low[200005],k=1;
vector<int>v[200005];
set<int>ans;
void dfs(int x,int pre){
    dfn[x]=low[x]=k++;
    bool flag=0;
    int child=0;
    for(auto i:v[x]){
        if(i==pre)continue;
        if(dfn[i]){
            low[x]=min(low[x],dfn[i]);
        }
        else{
            child++;
            dfs(i,x);
            low[x]=min(low[x],low[i]);
            if(dfn[x]<=low[i])flag=1;
            //if(dfn[x]<low[i])r.push_back({x,i}); -> bridge
         }
    }
    if((dfn[x]==1&&child>=2)||(flag&&dfn[x]!=1))ans.insert(x);
}
main(){
    add_edge();// both side
    dfs(1,0);
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i<<" ";
}