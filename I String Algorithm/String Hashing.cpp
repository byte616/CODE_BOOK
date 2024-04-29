//The time complexity of compare two string is O(logN) + O(N)
//O(N) for preprocessing
//O(logN) for query
//using hashing O(1) + binary search O(logN) to find the longest common prefix string
//then checkout the first different character to find which is bigger

long long BASE = 131;
long long MOD = 1256774137;			//this is a prime
long long M2 =  998244353;			//this is a prime
long long prefix[2000006];
long long deg[2000006];
string s;

//the mod operation is wasted time

long long hash_v(int left, int right){
    // cout<<"hash_v "<<left<<" "<<right<<endl;
    int len = right - left + 1;
    long long h = ((right >= 0?prefix[right]:0) - ((left == 0?0:prefix[left-1]) * deg[len])) % MOD;
    return h >= 0? h : h + MOD;
}


bool same(int l1, int l2, int len){
    long long h1 = hash_v(l1, l1 + len-1);
    long long h2 = hash_v(l2, l2 + len-1);
    if(h1 == h2)    return true;
    return false;
}

bool bigger(int l1, int l2, int len){
    int l = -1, r = len, mid;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(same(l1, l2, mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    if(r == len)    return false;
    if(s[l1+l] > s[l2+l])   return true;
    if(s[l1+l] < s[l2+l])   return false;
    cout<<"bug"<<'\n';
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int len = s.length();
    s = s + s;
    prefix[0] = s[0];
    deg[0] = 1;
    for(int i=1;i<s.length();i++){
        deg[i] = (deg[i-1] * BASE);
        prefix[i] = ((prefix[i-1] * BASE) + s[i]);
        if(deg[i] >= MOD)    deg[i] %= MOD;
        if(prefix[i] >= MOD)    prefix[i] %= MOD;
    }
    int mi = 0;
    for(int i=1;i<len;i++){
        if(bigger(mi, i, len)){
            mi = i;
        }
    }
    string ans = "";
    for(int i=mi;i<mi+len;i++){
        ans += (s[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
