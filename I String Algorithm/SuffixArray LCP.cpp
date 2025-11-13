// suffix array: O(n \log^2 n) 
// lcp: O(n) after create suffix array
// suffix array: sort the suffix substring
// lcp: longest common prefix
// Ex: abaa
// 	suffix array: 
// 	3 a
// 	2 aa
// 	0 abaa
// 	1 baa
// 	lcp: 1 1 0 0
// For counting number of distinct substring: N - sa[i] - lcp[sa[i-1]]
vector<int> rk(100005, 0), sec(100005, 0), sa(100005, 0), tmp(100005, 0);
vector<int> isa(100005, 0), lcp(100005, 0); 

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
	for(int i=0;i<N;i++){
        isa[sa[i]] = i;
    }
    int k = 0;
    for(int i=0;i<N;i++){
        int pi = isa[i];
        int pj = sa[pi - 1];
        if(pi == 0) continue;
        while(i+k < N && pj + k < N && s[i+k] == s[pj+k]){
            k++;
        }
        lcp[pj] = k;
        //cout<<"pi = "<<pi<<", pj = "<<pj<<", k = "<<k<<'\n';
        k = max(k-1, 0);
    }

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
 
