// LCS to LIS
// s1[1~6] = {a, b, c , a, d, c}
// s2[1~7] = {c, a, b, e, d, a, b}
// s2 location --> loc(a) = {6, 2}, loc(b) = {7, 3}, loc(c) = {1}, loc(d) = {5} 
// loc must reverse
// s1 --> s3 = {(6, 2), (7, 3), 1, (6, 2), 5, 1}
// s3: {6, 2, 7, 3, 1, 6, 2, 5, 1} --> solve LIS (nlogn)
vector<int> mp[100005];
int main() {
    int n, k, m;
    cin >> n >> k;
    m = n * k;
    int arr1[m + 5], arr2[m + 5];
    for(int i = 1; i <= m; i++) {
            cin >> arr1[i];
    }
    for(int i = 1; i <= m; i++) {
            cin >> arr2[i];
            mp[arr2[i]].push_back(i);
    }
    vector<int> v;
    for(int i = 1; i <= m; i++) {
            for(int j = k - 1; j >= 0; j--) {
                v.push_back(mp[arr1[i]][j]);
            }
    }
    // LIS
    vector<int> ans = {v[0]};
    for(int i = 1; i < v.size(); i++) {
        if(ans.back() < v[i]) ans.push_back(v[i]);
        else *lower_bound(ans.begin(), ans.end(), v[i]) = v[i];
    }
    cout << ans.size() << '\n';
}