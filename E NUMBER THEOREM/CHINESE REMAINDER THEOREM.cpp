// M = m1*m2*m3*...*mn
// ti≡Mi^-1(mod mi), Mi=M/mi
ll res[20],mod[20],t,ans=0,T,M=1;
ll modrev(ll a,ll n){
    ll d,x,y;
    d=exgcd(a,n,x,y);
    return (x%n+n)%n;
}
main(){
    cin>>T; // T equations
    // X ≡ res[i] (mod mod[i])
    for(int i=0;i<T;i++)cin>>mod[i]>>res[i],M*=mod[i];
    for(int i=0;i<T;i++){
        t=modrev(M/mod[i],mod[i]);
        ans=(ans+res[i]*t*(M/mod[i]))%M;
    }
    cout<<ans%M<<'\n';
}