// O(N) to find Eulerian circuit
 
 
struct Edge{
	int to;
	int rev_id;
	bool use;
	Edge(){};
	Edge(int neighbor, int id, bool used = false):
		to(neighbor), rev_id(id), use(used){};
};
 
 
vector<vector<Edge>> adj;
int degree[100005];
bool vis[100005];
vector<int> circuit;
const int UNDIRECTOR_GRAPH = 2022;
 
 
void dfs(int node){
	vis[node] = true;
	while(adj[node].size() != 0){
		Edge& e = adj[node].back();
		adj[node].pop_back();
		if(e.use == true)	continue;
		//prevent link second visited
		e.use = true;
		degree[node]--;
		// prevent reverse link
		adj[e.to][e.rev_id].use = true;
		degree[e.to]--;
		
		dfs(e.to);
	}
	circuit.emplace_back(node);
}
 
 
void init(int mode, int n, int m){
	adj.clear();
	circuit.clear();
	for(int i=1;i<=n;i++){
		degree[i] = 0;
	}
	adj.resize(n+5);
	if(mode == UNDIRECTOR_GRAPH){
		adj.resize(n+5);
		for(int i=0, n1, n2;i<m;i++){
			cin>>n1>>n2;
			adj[n1].emplace_back(n2, adj[n2].size());
			adj[n2].emplace_back(n1, adj[n1].size()-1);
			degree[n1]++, degree[n2]++;
		}
	}
}
 
bool find_Euler_circuit(int mode, int n, int m){
	if(mode == UNDIRECTOR_GRAPH){
		init(mode, n, m);
		for(int i=1;i<=n;i++){
			if(degree[i] % 2 != 0){
				return false;
			}
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			if(degree[i] != 0){
				return false;
			}
		}
	}
	return true;
}
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	if(find_Euler_circuit(UNDIRECTOR_GRAPH, n, m)){
		for(const int& c:circuit){
			cout<<c<<" ";
		}
		cout<<'\n';
	}else{
		cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
