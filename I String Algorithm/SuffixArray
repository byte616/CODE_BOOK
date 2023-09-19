vector<int> rk(100005, 0), sec(100005, 0), sa(100005, 0), tmp(100005, 0);
 
bool cmp(int x, int y){
    if(rk[x] != rk[y]){
        return rk[x] < rk[y];
    }
    return sec[x] < sec[y];
}
 
void find_rank(const string &s){
    int N = s.length();
    for(int i=0;i<N;i++){
        sa[i] = i;
        rk[i] = s[i];
    }
    sort(sa.begin(), sa.begin()+N, cmp);
    for(int i=1;i<N;i<<=1){
        for(int j=0;j<s.length();j++){
            if(i+j < N) sec[j] = rk[j+i];
            else sec[j] = -1;
        }
        sort(sa.begin(), sa.begin()+N, cmp);
        int r = 0;
        tmp[sa[0]] = 0;
        for(int j=1;j<N;j++){
            if(rk[sa[j]] == rk[sa[j-1]] && sec[sa[j]] == sec[sa[j-1]]){
                tmp[sa[j]] = tmp[sa[j-1]];
            }else{
                tmp[sa[j]] = ++r;
            }
        }
        swap(rk, tmp);
    }
    /*for(int i=0;i<N;i++){
        cout<<sa[i]<<" ";
    }
    cout<<'\n';*/
}
 
bool check(int pos, const string &from, const string &target){
    pos = sa[pos];
    int N = from.length();
    for(int i=0;i<min((int)target.length(), N-pos);i++){
        if(from[pos+i] != target[i]){
            return from[pos+i] >= target[i];
        }
    }
    if(target.length() <= N-pos){
        return true;
    }
    return false;
}
 
 
// Be careful about adding reference or not
// without & will get TLE 
int lowerBound(const string &s, const string &t, int start_pos = 0){
	int l = start_pos - 1, r = s.length();
	while(r - l > 1){
		int pos = (r + l) / 2;
		if(check(pos, s, t)){
			r = pos;
		}else{
			l = pos;
		}
	}
	l++;
	return l;
}
 
