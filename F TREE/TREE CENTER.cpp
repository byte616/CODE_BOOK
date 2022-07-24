int mx[MAX_N],idx[MAX_N],dis1[MAX_N],dis2[MAX_N];
bool vis1[MAX_N],vis2[MAX_N];
vecotr<int>v[MAX_N];
queue<int>q1,q2;
void bfs(int start,queue<int>q,bool vis[],int dis[],int target){
    q.push(start);
    vis[start]=1;
    dis[start]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(dis[u]>target)break;
        for(auto i:v[u]){
            if(!vis[i]){
                dis[i]=dis[u]+1;
                vis[i]=1;
                q.push(i);
            }
        }
    }
}
main(){
    add_edge();// both side
    find_far(1,0);
    int root=idx[1];
    find_far(root,0);
    int node1=root,node2=idx[root];
    int target=round((double)mx[root]/2);
    bfs(node1,q1,vis1,dis1,target);
    bfs(node2,q2,vis2,dis2,target);
    for(int i=1;i<=n;i++){
        if(vis1[i]&&vis2[i]){
            cout<<i;
            break;
        }
    }
}