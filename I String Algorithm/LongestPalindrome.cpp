// O(|S|)

int rad[2000006];

// 只看 odd length
// rad[i]: 以 i 為中心的最大回文半徑
void manacher(const string &s){
    int l = 0, r = 0;
    rad[0] = 1;
    for(int k=1;k<s.length();k++){
        if(k <= r){
            rad[k] = min(r-k+1, rad[l+r-k]);
        }
        while(k+rad[k] < s.length() && k-rad[k] >= 0 && s[k+rad[k]] == s[k-rad[k]]){
            rad[k]++;
        }
        if(k+rad[k] > r){
            l = k - rad[k] + 1;
            r = k + rad[k] - 1;
        }
    }
}

int main(){
    string s;
    cin>>s;
    string input(s.length()*2-1, '#');
    for(int i=0;i<s.length();i++){
        input[i*2] = s[i];
    }
    manacher(input);
    int mx = 0;
    int mx_pos = -1;
    for(int i=0;i<input.length();i++){
        int len;
        if(i % 2 == 0){
            len = rad[i]-1;
            len = (len/2) * 2 + 1;
        }
        else{
            len = rad[i]-1;
            len = ((len+1) / 2) * 2;
        }
        if(len > mx){
            mx = len;
            mx_pos = i;
        }
    }
    int st_pos = mx_pos - rad[mx_pos] + 1;
    int vir_len = rad[mx_pos] * 2 - 1;
    for(int i=0;i<vir_len;i++){
        if(input[st_pos+i] != '#'){
            cout<<input[st_pos+i];
        }
    }
    cout<<'\n';
    return 0;
}
