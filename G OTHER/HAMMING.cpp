// find minimum hamming distance --> brute force
vector<int> v;
int n, m;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, ans = 30;
    string s;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        int x = 0;
        for(int j = 0; j < s.size(); j++){
            x |= (s[j] == '1') * (1 << j);
        }
        v.push_back(x);
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans = min(ans, __builtin_popcount(v[i] ^ v[j]));
        }
    }
    cout << ans << '\n';
}
