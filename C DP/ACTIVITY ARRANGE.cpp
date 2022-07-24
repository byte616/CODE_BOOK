struct act{
    int s,e,w; // s -> start, e -> end, w -> weight
}p[200005];
bool cmp(act a,act b){
    if(a.e!=b.e)return a.e<b.e;
    return a.s<b.s;
}
int n,eend[200005];
long long dp[200005];
main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i].s>>p[i].e>>p[i].w;
    sort(p+1,p+1+n,cmp);
    for(int i=1;i<=n;i++)eend[i]=p[i].e;
    for(int i=1;i<=n;i++)dp[i]=max(dp[i-1],dp[lower_bound(eend+1,eend+i,p[i].s)-(eend+1)]+p[i].w);
    cout<<dp[n]<<'\n';
}