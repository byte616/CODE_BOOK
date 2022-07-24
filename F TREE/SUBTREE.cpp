int sz[MAX_N];
vector<int>v;// edge single side
void dfs(int x){
	sz[x]=1;
	for(auto i:v[x]){
		dfs(i);
		sz[x]+=sz[i];
	}
}
dfs(1);