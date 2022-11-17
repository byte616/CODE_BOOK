vector<pii> v[200005]; // adjacent node : edge index
vector<int> ans;
int n, m, a, b, idx;
int deg[200005];
bool vis_node[200005], vis_edge[200005];
void dfs(int x){
    vis_node[x] = 1;
    while(!v[x].empty()){
        auto i = v[x].back();
        v[x].pop_back();
        if(!vis_edge[i.s]){
            vis_edge[i.s] = 1;
            dfs(i.f);
            ans.push_back(i.f);
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        deg[a]++, deg[b]++;
        v[a].push_back({b, idx});
        v[b].push_back({a, idx++});
    }
    dfs(1);
    ans.push_back(1);
    for(int i = 1; i <= n; i++){
        if(deg[i] & 1 || (!vis_node[i] && deg[i])){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    for(auto i : ans) cout << i << " ";
}
