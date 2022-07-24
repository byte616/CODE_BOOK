#include<iostream>
#include<vector>
using namespace std;
#define Edge_situation 0;
 
vector<vector<int>> adj;
vector<int> path;
int heavy_child[200005];
int head[200005];
int pos[200005];
int val[200005];
int deepth[200005];
int parent[200005];
 
int dfs(int node, int par){
    int tree_size = 1, tmp, c_size = 0;
    deepth[node] = deepth[par]+1;
    parent[node] = par;
    for(int& u:adj[node]){
        if(u == par){continue;}
        tmp = dfs(u, node);
        tree_size += tmp;
        if(tmp > c_size){
            c_size = tmp;
            heavy_child[node] = u;
        }
    }
    return tree_size;
}
 
void decomposition(int node, int h){
    head[node] = h, pos[node] = path.size();
    path.emplace_back(node);
    if(heavy_child[node] != 0){
        decomposition(heavy_child[node], h);
    }
    for(int& u:adj[node]){
        if(u == parent[node]){continue;}
        if(u == heavy_child[node]){continue;}
        decomposition(u, u);
    }
}
 
struct Node{
    int L, R;
    int data;
}tree[800020];
 
void build(int idx, int L, int R){
    tree[idx].L = L;
    tree[idx].R = R;
    if(L == R){
        tree[idx].data = val[path[L]];
        return;
    }
    int MID = (L+R)/2;
    build(idx*2, L, MID);
    build(idx*2+1, MID+1, R);
    tree[idx].data = max(tree[idx*2].data, tree[idx*2+1].data);
}
 
void update(int idx, int position, int modify){
    if(tree[idx].L > position or tree[idx].R < position){return;}
    if(tree[idx].L == position and tree[idx].L == tree[idx].R){
        tree[idx].data = modify;
        return;
    }
    update(idx*2, position, modify);
    update(idx*2+1, position, modify);
    tree[idx].data = max(tree[idx*2].data, tree[idx*2+1].data);
}
 
int query(int idx, int qL, int qR){
    if(tree[idx].L > qR or tree[idx].R < qL){return Edge_situation;}
    if(tree[idx].L >= qL and tree[idx].R <= qR){
        return tree[idx].data;
    }
    return max(query(idx*2, qL, qR), query(idx*2+1, qL, qR));
}
 
 
int find_max(int s, int t){
    int mx = 0;
    while(head[s] != head[t]){
        if(deepth[head[s]] < deepth[head[t]]){
            swap(s, t);
        }
        mx = max(mx, query(1, pos[head[s]], pos[s]));
        s = parent[head[s]];
    }
    if(deepth[s] > deepth[t]){swap(s, t);}
    mx = max(mx, query(1, pos[s], pos[t]));
    return mx;
}
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    adj.resize(n+5);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1, x, y;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    decomposition(1, 1);
    build(1, 0, path.size()-1);
    int mode, a, b;
    while(q--){
        cin>>mode>>a>>b;
        if(mode == 1){
            update(1, pos[a], b);
        }else{
            cout<<find_max(a, b)<<' ';
        }
    }
    cout<<'\n';
    return 0;
}
