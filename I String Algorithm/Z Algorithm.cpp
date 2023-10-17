int z[2000006];
 
void Z_algorithm(const string &s){
    // O(|S|)
    int x = 0, y = 0;
    z[0] = -1;
    for(int k=1;k<s.length();k++){
        if(k <= y){
            z[k] = min(y-k+1, z[k-x]);
        }
        while(k+z[k] < s.length() && s[k+z[k]] == s[z[k]]){
            z[k]++;
        }
        if(k+z[k]-1 > y){
            x = k, y = k+z[k]-1;
        }
    }
}

// z algorithm used in pattern matching
int main(){
    string s, t;
    cin>>s>>t;
    int patterlen = t.length();
    t += "#" + s;
    Z_algorithm(t);
    int cnt = 0;
    for(int i=beg;i<t.length();i++){
        if(z[i] == patterlen){
            cnt++;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}
