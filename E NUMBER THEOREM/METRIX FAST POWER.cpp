const long long MOD = (long long)(1e9+7);
 
struct Metric{
    int r, c;
    vector<vector<long long>> m;
    Metric(int _r, int _c):r(_r), c(_c){
        m.resize(r);
        for(int i=0;i<r;i++){
            m[i].resize(c);
        }
    }
    Metric operator * (const Metric& right){
        if(c != right.r){
            exit(1);
        }
        Metric tmp(r, right.c);
        for(int i=0;i<tmp.r;i++){
            for(int j=0;j<tmp.c;j++){
                for(int k=0;k<c;k++){
                    tmp.m[i][j] += m[i][k] * right.m[k][j];
                    tmp.m[i][j] %= MOD;
                }
            }
        }
        return tmp;
    }
    void display(){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<m[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
};
 
 
Metric fast_power(Metric base, long long n){
    if(base.r != base.c)    exit(1);
    Metric res(base.r, base.c);
 
    //identity metrix
    for(int i=0;i<res.r;i++){
        for(int j=0;j<res.c;j++){
            if(i == j)    res.m[i][j] = 1;
            else    res.m[i][j] = 0;
        }
    }
 
 
    while(n != 0){
        if(n & 1){
            res = base * res;
        }
        base = base * base;
        n /= 2;
    }
    return res;
}

