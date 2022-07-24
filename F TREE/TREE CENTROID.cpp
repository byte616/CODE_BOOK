vector<vector<int>> v;
int tree_size[200005];//initial is needed
int n;

int dfs_size_finding(int node, int par){
    tree_size[node] = 1;
    for(int& e:v[node]){
        if(e != par){
            tree_size[node] += dfs_size_finding(e, node);
        }
    }
    return tree_size[node];
}

int find_centroid(int node, int par){
    // keep special case n=1 in mind
    for(int& u:v[node]){
        if(u != par and (tree_size[u] > n/2)){
            return find_centroid(u, node);
        }
    }
    return node;
}
