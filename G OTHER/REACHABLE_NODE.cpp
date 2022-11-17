// Calculate the number of nodes you can reach for each nodes
vector<int> v[50005];
bitset<50005> node[50005];
bool vis[50005];
int n, m, a, b;
void dfs(int x){
    node[x][x] = 1;
    vis[x] = 1;
    for(auto i : v[x]){
        if(!vis[i]){
            dfs(i);
        }
        node[x] |= node[i];
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
        cout << node[i].count() << ' ';
    }
}