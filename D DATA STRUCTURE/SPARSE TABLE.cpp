ll sp[20][200005],n,q,a,b;
ll log2(ll x){
	ll cnt=0;
	while(x>1)x/=2,cnt++;
	return cnt;
}
void sparse_table(){
    for(int i=0;i<n;i++)cin>>sp[0][i];
	for(int i=1;(1<<i)<=n;i++){
		for(int j=0;j+(1<<i)<=n;j++){
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
		}
	}
}
ll query(ll le,ll ri){
	int k=log2(ri-le);
	return min(sp[k][le],sp[k][ri-(1<<k)+1]);
}
main(){
	sparse_table();
	while(q--){
		cin>>a>>b;
		cout<<query(--a,--b)<<'\n';
	}
}