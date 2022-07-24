ll fp(ll a,ll b,ll p){
    ll res=1;
    while(b){
        if(b&1)res=res*a%p;
        b>>=1;
        a=a*a%p;
    }
    return res;
}