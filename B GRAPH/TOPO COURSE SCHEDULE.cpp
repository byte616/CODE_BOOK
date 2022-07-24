// can slove by topological sort
int n,m,num[MAX_N];
vector<int>v[100005],ans;
queue<int>q;
main(){
	cin>>n>>m;// n vertices and m rules
	while(m--){
		cin>>a>>b;// a should set before b
		v[a].push_back(b);
		num[b]++;// how many number before it
	}
        //choose number=0, push it into queue
	for(int i=1;i<=n;i++)if(!num[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		ans.push_back(u);
		for(auto k:v[u]){
			num[k]--;//we put u into ans, so num--
			if(!num[k])q.push(k);
		}
	}
	if(ans.size()==n)for(auto i:ans)cout<<i<<" ";
	else cout<<"IMPOSSIBLE";
}