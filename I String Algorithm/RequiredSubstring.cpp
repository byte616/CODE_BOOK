// calculate the number of strings of length n having a given pattern of length m as their substring. 
// All strings consist of characters A–Z.
// O(|S|)
// 6 ABCDB -> 52
const long long MOD = 1e9+7;

int z[105];                 // 從 i 開始和開頭最長有幾個一樣
int fail[105];              // 當 match pos+1 失敗時，可以從 fail[pos] 重新 match
int matchTable[105][30];    // match 到 i-1 並且下一個字元為 j 時的 match 數
long long dp[1003][105];


void z_algorithm(const string &s){
    for(int i=0;i<s.length();i++){
        fail[i] = -1;
    }
    z[0] = 1;
    int l = 0, r = 0;
    for(int i=1;i<s.length();i++){
        if(i <= r){
            z[i] = min(r-i+1, z[i-l]); 
        }
        while(i+z[i] < s.length() && s[i+z[i]] == s[z[i]]){
            z[i]++;
            int tmpR = i + z[i] - 1;
            fail[tmpR] = max(fail[tmpR], z[i]-1);
        }
        if(i+z[i] > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
}


void build(const string &s){
    for(int i=0;i<s.length();i++){
        for(int j=0;j<26;j++){
            int pos = i-1;
            while(pos != -1 && s[pos+1] != j + 'A'){
                pos = fail[pos];
            }
            if(s[pos+1] == j + 'A'){
                pos++;
            }
            matchTable[i][j] = pos;
        }
    }
}

int main(){
    int n;
    string s;
    cin>>n>>s;
    z_algorithm(s);
    build(s);
    // dp[i][j]: 考慮長度為 i 並且 match 到 idx j(1-based) 的情況下的所有字串數量
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<s.length();j++){
            for(int c=0;c<26;c++){
                int nxt_pos = matchTable[j][c] + 1;
                dp[i+1][nxt_pos] += dp[i][j];
                dp[i+1][nxt_pos] %= MOD;
            }
        }
        dp[i+1][s.length()] += 26 * dp[i][s.length()];
        dp[i+1][s.length()] %= MOD;
    }

    cout<<dp[n][s.length()]<<'\n';

    return 0;
}
