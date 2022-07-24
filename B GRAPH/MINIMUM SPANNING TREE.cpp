struct edge{
    int a,b;
    ll w;
}r[MAX_M];
bool cmp(edge a,edge b){return a.w<b.w;}
int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}
bool uni(int a,int b){
    int _a=find(a),_b=find(b);
    if(_a==_b)return 0;
    pa[_b]=_a;
    return 1;
}
int n,m,pa[MAX_N];
ll MST(){
    input();
    for(int i=1;i<=n;i++)pa[i]=i;
    sort(r,r+m,cmp);
    int cnt=n-1;
    ll ans=0;
    for(int i=0;i<m;i++){
        if(uni(r[i].a,r[i].b)){
            ans+=r[i].w,cnt--;
        }
    }
    if(!cnt)return ans;
    return INF;
}