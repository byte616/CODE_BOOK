bool is_prime(ll n){
    if(n==2||n==3)return 1;
    if(n<=1||!(n&1))return 0;
    ll s=0,d,k=10,m=n-1;// k 可調動
    while(m%2==0&&m){
        s++;
        m/=2;
    }
    d=m;
    while(k--){
        ll a=rand()%(n-3)+2;
        ll x=fp(a,d,n);
        bool flag=0;
        if(x==1||x==n-1)continue;
        for(int i=1;i<=s-1;i++){
            x=mul(x,x,n);
            if(x==n-1){
                flag=1;
                break;
            }
        }
        if(!flag)return 0;
    }
    return 1;
}
main(){
    ll x;
    while(cin>>x){
        cout<<(is_prime(x)?"isprime\n":"oh no\n");
    }
}