int n,m;//n->left size : m->right size
int match[MAX_N];
bool vis[MAX_N];
vector<int>v[MAX_N];
void add_edge(int left,int right){
    v[left].push_back(right);
}
bool dfs(int x){
    for(auto i:v[x]){
        if(vis[i])continue;
        vis[i]=1;
        if(match[i]==0||dfs(match[i])){
        //match[i]==0->didn't match with other
            match[i]=x;
            return 1;        
        }
    }
    return 0;
}
int Bipartite_match(){
    add_edge();
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i))ans++;
    }
    return ans;
}

