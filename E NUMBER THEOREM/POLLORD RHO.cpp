map<ll,int>mp;
ll fp(ll a,ll b,ll p){
    ll res=1;
    while(b){
        if(b&1)res=mul(res,a,p);
        b>>=1;
        a=mul(a,a,p);
    }
    return res;
}
ll gcd(ll a,ll b){
    if(!b)return a;
    return gcd(b,a%b);
}
ll f(ll x,ll c,ll p){
    return (mul(x,x,p)+c)%p;
}
void pollard(ll n){
  if(is_prime(n))mp[n]++;
  else if(n==4)mp[2]+=2;
  else if(n>1){
        ll d;
        while(1){
            d=1;
            ll x=rand()%n;
            ll c=rand()%n;
            ll y=f(x,c,n);
            while(d==1&&x!=y){
                x=f(x,c,n);
                y=f(f(y,c,n),c,n);
                d=gcd(abs(x-y),n);
            }
            if(d==n)continue;
            break;
        }
        pollard(d);
        pollard(n/d);
    }
}
main(){
    srand(time(NULL));
    while(cin>>n){
        mp.clear();
        pollard(n);
        for(auto i:mp)cout<<i.f<<" "<<i.s<<" ";
        cout<<'\n';
    }
}