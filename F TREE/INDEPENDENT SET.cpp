// no -> choose yes or no
// yes -> choose no
vector<int>v[MAX_N];
int pa,yes[MAX_N],no[MAX_N],arr[1005],t,n,r;
void dfs(int x){
	for(auto k:v[x]){
		dfs(k);
		yes[x]+=no[k];
		no[x]+=max(no[k],yes[k]);
	}
	yes[x]+=arr[x];
}
int main(){
    cin>>n>>arr[1];// n vertice, arr[1] -> value
    for(int i=2;i<=n;i++){
        cin>>pa>>arr[i];
        v[pa].push_back(i);
    }
    dfs(1);
    cout<<max(yes[1],no[1])<<'\n';
}