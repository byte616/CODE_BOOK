// the rotations of acab are acab, caba, abac, and baca.
// determine the lexicographically minimal rotation of a string.
// O(|S|log|S|)

// solution: hash+binary search
#include<iostream>
using namespace std;
 
long long BASE = 256;
long long MOD = 1256774137;         //this is a prime
long long prefix[2000006];
long long deg[2000006];
string s;
 
//the mod operation is wasted time
 
long long hash_v(int left, int right){
    //cout<<"hash_v"<<left<<" "<<right<<endl;
    int len = right - left + 1;
    long long h = (prefix[right] - ((left == 0?0:prefix[left-1]) * deg[len])) % MOD;
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
    cout<<"bug"<<endl;
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


// another solution (Lyndon factorization)
#include<iostream>
using namespace std;


int main(){
    string s;
    cin>>s;
    int len = s.length();
    s = s + s + "|";
    int pos = 0, cur = 1;
    while(pos < len && cur < len){
        int k = 0;
        while(k < len && s[pos+k] == s[cur+k]){
            k++;
        }
        if(s[pos+k] <= s[cur+k]){
            cur = cur + k + 1;
        }
        else{
            pos = max(cur, pos+k+1);
            cur = pos+1;
        }
    }
    for(int i=0;i<len;i++){
        cout<<s[pos+i];
    }
    cout<<'\n';
    return 0;
}
