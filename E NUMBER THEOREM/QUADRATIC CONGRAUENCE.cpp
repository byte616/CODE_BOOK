struct W{
    ll a,b; //a + b*sqrt(w)
    W(ll x){a=x;b=0;}
    W(){a=0;b=0;}
};
ll t,a,b,d,p,w,ran;
W operator %(W x,ll p){
    W res;
    res.a=x.a%p; 
    res.b=x.b%p;
    return res;
}
W operator *(W x,W y){
    W res;
    res.a=(x.a*y.a%p+x.b*y.b%p*w%p)%p;
    res.b=(x.a*y.b%p+x.b*y.a%p)%p;
    return res;
}
template<class T>T fp(T a,ll b,ll p){
    T res=1;
    while(b){
        if(b&1)res=res*a%p;
        b>>=1;
        a=a*a%p;
    }
    return res;
}
ll rev(ll a,ll p){
    return fp(a,p-2,p);
}
bool is_slove(ll d,ll p){
    d=(d%p+p)%p;
    return fp(d,(p-1)>>1,p)==1;
}
int main(){
    cin>>t;// t case
    while(t--){// a(x+b)^2 ≡d (mod p) -> 求 x
        cin>>a>>b>>d>>p;
        d=(d*rev(a,p))%p;// d * a^-1
        if(!d)cout<<p-b<<'\n';
        else if(!is_slove(d,p))cout<<-1<<'\n';
        else{
            do{
                ran=rand()%p;
                w=(ran*ran-d)%p;
                w=(w+p)%p;
            }while(is_slove(w,p));//fp --> -1 is what we need
            W x;
            x.a=ran,x.b=1;
            x=fp(x,(p+1)>>1,p); //x.a & p-x.a is y's ans
            ll x1=((x.a-b)%p+p)%p;
            ll x2=((p-x.a-b)%p+p)%p;
            if(x1!=x2)cout<<min(x1,x2)<<" "<<max(x1,x2)<<'\n';
            else cout<<x1<<'\n';
        }
    }
}