char maps[205][205], x;
bool adj[205][205];
int n, m, arr[205][205], ret;
int dx[] = {1, -1, 1, -1};
int dy[] = {-1, 1, 1, -1};
bool is_valid1(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
bool is_valid2(int x, int y){
    return 1 <= x && x <= n + 1 && 1 <= y && y <= m + 1; 
}
void dfs(int x, int y){
    ret += abs(arr[x][y]);
    adj[x][y] = 0;
    if(is_valid1(x, y - 1) && (maps[x][y-1] == '/' || maps[x][y-1] == 'X')){
        int X = x + dx[0], Y = y + dy[0];
        if(is_valid2(X, Y) && adj[X][Y])
            dfs(X, Y);
    }
    if(is_valid1(x - 1, y) && (maps[x-1][y] == '/' || maps[x-1][y] == 'X')){
        int X = x + dx[1], Y = y + dy[1];
        if(is_valid2(X, Y) && adj[X][Y])
            dfs(X, Y);
    }
    if(is_valid1(x,y) && (maps[x][y] == '\\' || maps[x][y] == 'X')){
        int X = x + dx[2], Y = y + dy[2];
        if(is_valid2(X, Y) && adj[X][Y])
            dfs(X, Y);
    }
    if(is_valid1(x-1,y-1) && (maps[x-1][y-1] == '\\' || maps[x-1][y-1] == 'X')){
        int X = x + dx[3], Y = y + dy[3];
        if(is_valid2(X, Y) && adj[X][Y])
            dfs(X, Y);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> maps[i][j];
            if(maps[i][j] == '\\' || maps[i][j] == 'X'){
                arr[i][j] += 1, arr[i + 1][j + 1] += 1;
                adj[i][j] = adj[i + 1][j + 1] = 1;
            }
            if(maps[i][j] == '/' || maps[i][j] == 'X'){
                arr[i][j + 1] += 1, arr[i + 1][j] += 1;
                adj[i][j + 1] = adj[i + 1][j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> x;
            if(maps[i][j] == '.') maps[i][j] = x;
            else if((maps[i][j] == '/' && (x == '\\' || x == 'X')) || (maps[i][j] == '\\' && (x =='/' || x == 'X'))){
                maps[i][j] = 'X';
            }
            if(x == '\\' || x == 'X'){
                arr[i][j] -= 1, arr[i + 1][j + 1] -= 1;
                adj[i][j] = adj[i + 1][j + 1] = 1;
            }
            if(x == '/' || x == 'X'){
                arr[i][j + 1] -= 1, arr[i + 1][j] -= 1;
                adj[i][j + 1] = adj[i + 1][j] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= m + 1; j++){
            if(adj[i][j]){
                ret = 0;
                dfs(i, j);
                ret = ret / 2;
                ans += (ret == 0 ? 1 : ret);
            }
        }
    }
    cout << ans << '\n';
}