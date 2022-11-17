/*
You are given a rooted tree consisting of n nodes.
The nodes are numbered 1,2,…,n, and node 1 is the root.
Each node has a value.
Your task is to process following types of queries:
    1. change the value of node s to x
    2. calculate the sum of values in the subtree of node s
*/

vector<vector<int>> v;
int val[200005];
int node_id[200005];
int sub_size[200005];
int id_value[200005];
int id = 0;

int dfs(int node, int par){
    node_id[node] = id;
    id_value[id] = val[node];
    id++;
    int ts = 1;
    for(int u:v[node]){
        if(u != par){
            ts += dfs(u, node);
        }
    }
    sub_size[node] = ts;
    return ts;
}

struct Node{
    int L, R;
    long long sum;
}tree[4*200005];

void build(int idx, int L, int R){
    tree[idx].L = L, tree[idx].R = R;
    if(L == R){
        tree[idx].sum = id_value[L];
        return;
    }
    int mid = (L+R)/2;
    build(idx*2, L, mid);
    build(idx*2+1, mid+1, R);
    tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
}

long long query(int idx, int qL, int qR){
    if(tree[idx].L > qR || tree[idx].R < qL){
        return 0;
    }
    if(tree[idx].L >= qL && tree[idx].R <= qR){
        return tree[idx].sum;
    }
    return query(idx*2, qL, qR) + query(idx*2+1, qL, qR);
}

void update(int idx, int pos, int mod){
    if(tree[idx].L > pos || tree[idx].R < pos){return;}
    if(tree[idx].L == pos && tree[idx].R == pos){
        id_value[pos] = mod;
        tree[idx].sum = mod;
        return;
    }
    update(idx*2, pos, mod);
    update(idx*2+1, pos, mod);
    tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
}

int main(){
    int n, q;
    cin>>n>>q;
    v.resize(n+5);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    int x, y;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    build(1, 0, id);
    while(q--){
        cin>>x>>y;
        if(x == 1){
            cin>>x;
            update(1, node_id[y], x);
        }else{
            cout<<query(1, node_id[y], node_id[y] + sub_size[y]-1)<<endl;
        }
    }
    return 0;
}
