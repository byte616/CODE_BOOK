int n,q,a,b,sz[200005],p[20][200005];
int ask_level(int x){
    if(sz[x])return sz[x];
    if(x==1)return sz[x]=1;
    return sz[x]=ask_level(p[0][x])+1;
}
int query(int a,int b){
    int x=ask_level(a),y=ask_level(b);
    if(x>y)swap(a,b),swap(x,y);
    y-=x;
    for(int i=0;i<20;i++){
        if(y&(1<<i))b=p[i][b];
    }
    if(b==a)return b;
    for(int i=19;i>=0;i--){
        if(p[i][a]!=p[i][b]){
            a=p[i][a];
            b=p[i][b];
        }
    }
    return p[0][b];
}
main(){
    for(int i=2;i<=n;i++)cin>>p[0][i];
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
    while(q--){
        cin>>a>>b;
        cout<<query(a,b)<<'\n';
    }
}