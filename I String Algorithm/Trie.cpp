//O(N) to find if the string is the k strings
//O(total length of k) preprocessing
//O(N^2) on dp to find word combinations

 
string s;
int trie[10000006][26];     //node(total length of all strings), alphabet
bool stop[1000006];
long long dp[5005];         //考慮 i ~ s.size() 的 word combinations
const int MOD = 1000000007;
 
void query(int x){
    int node = 0;
    for(int i=x;i<s.length();i++){
        node = trie[node][s[i]-'a'];
        if(node == 0)   return;
        if(stop[node]){
            dp[x] += dp[i+1];
            dp[x] %= MOD;
        }
    }
}
 
 
int main(){
    string t;
    cin>>s;
    int k;
    cin>>k;
    int N = 0, status = 0, id, last;
    
    //build trie
    for(int i=0;i<k;i++){
        last = 0;
        status = id = 0;
        cin>>t;
        while(id < t.length() && (status = abs(trie[status][t[id]-'a'])) != 0){
            last = status;
            id++;
        }
        while(id < t.length()){ 
            trie[last][t[id]-'a'] = ++N;
            last = trie[last][t[id]-'a'];
            id++;
        }
        stop[last] = true;      //when arrived stop node -> exist a string
    }
    
    //dp on trie
    dp[s.length()] = 1;
    for(int i=(int)s.length()-1;i>=0;i--){
        query(i);
    }
    cout<<dp[0]<<endl;
    return 0;
}

