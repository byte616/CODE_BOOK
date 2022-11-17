struct node{
    int x, y, g, h; // (x, y), cur_dis, h(繞路走的長度，找最小值)
    node(int _x, int _y, int _g, int _h): x(_x), y(_y), g(_g), h(_h){}
    bool operator < (const node &x) const{
        return x.h < h;
    }
};
int t, n, m;
int wall[45][45][4], dis[45][45], dp[45][45][45 * 45];
// right down left up
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char maps[45][45];
pii st, en;
bool is_valid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m && maps[x][y] != '#'; 
}
int shortest_path(){
    priority_queue<node> pq;
    pq.push(node(st.f, st.s, 0, 0));
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        if(u.h > dp[u.x][u.y][u.g]) continue;
        if(u.x == en.f && u.y == en.s) return u.h;
        for(int i = 0; i < 4; i++){
            int x = u.x + dx[i], y = u.y + dy[i], h;
            if(!is_valid(x, y)) continue;
            if(maps[x][y] == '.'){
                h = max(u.h, u.g + wall[u.x][u.y][i]);
            }
            if(maps[x][y] == 'X'){
                h = max(u.h, u.g);
            }
            if(dp[x][y][u.g + 1] > h){
                dp[x][y][u.g + 1] = h;
                pq.push(node(x, y, u.g + 1, h));
            }
        }
    }
    return 0;
}
void bfs(){
    queue<pii> q;
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    q.push({en.f, en.s});
    dis[en.f][en.s] = 0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = u.f + dx[i], y = u.s + dy[i];
            if(is_valid(x, y) && dis[u.f][u.s] + 1 < dis[x][y]){
                dis[x][y] = dis[u.f][u.s] + 1;
                q.push({x, y});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> maps[i][j];
                if(maps[i][j] == 'E') st = {i, j};
                if(maps[i][j] == 'X') en = {i, j};
            }
        }
        // 窮舉牆壁
        memset(wall, 0x3f3f3f3f, sizeof(wall));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(maps[i][j] != '.') continue;
                maps[i][j] = '#';
                bfs(); // 終點搜回去
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k], y = j + dy[k];
                    if(is_valid(x, y)){
                        wall[x][y][(k + 2) % 4] = dis[x][y]; // right down left up
                    }
                }
                maps[i][j] = '.';
            }
        }
        cout << shortest_path() << '\n';
    }
}

