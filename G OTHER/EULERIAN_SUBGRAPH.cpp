// find nuber of cycle, choose or not choose
// eulerian subgraph: each node has even degree
const int p = 1000000007;
int n, m, a, b, cnt, vis[200005];
long long ans = 1;
vector<int> v[200005];
void dfs(int x, int pre){
    if(vis[x]) return;
    vis[x] = 1;
    for(auto i : v[x]){
        if(i == pre) continue;
        if(vis[i] == 1) cnt++;
        if(vis[i] == 0) dfs(i, x);
    }
    vis[x] = 2;
}
long long fast_pow(long long x, int y){
    long long ret = 1;
    while(y){
        if(y & 1) ret = ret * x % p;
        y >>= 1;
        x = x * x % p;
    }
    return ret;
}
int main(){
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cnt = 0;
            dfs(i, 0);
            ans = (ans * fast_pow(2, cnt)) % p;
        }
    }
    cout << ans << '\n';
}