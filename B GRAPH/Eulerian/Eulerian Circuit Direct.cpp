// O(N) to find Eulerian circuit
// transform Eulerian circuit to Eulerian path : add a link from source to destination
// after finding circuit and delete the added edge
 
vector<vector<int>> adj;
int in_degree[100005], out_degree[100005];
vector<int> circuit;
const int DIRECTOR_GRAPH = 2023;
 
 
void dfs(int node){
	while(adj[node].size() != 0){
		int e = adj[node].back();
		adj[node].pop_back();
        out_degree[node]--;
		in_degree[e]--;
		dfs(e);
	}
	circuit.emplace_back(node);
}
 
 
void init(int mode, int n, int m){
	adj.clear();
	circuit.clear();
	for(int i=1;i<=n;i++){
		in_degree[i] = 0;
        out_degree[i] = 0;
	}
	adj.resize(n+5);
	if(mode == DIRECTOR_GRAPH){
		for(int i=0, n1, n2;i<m;i++){
			cin>>n1>>n2;
			adj[n1].emplace_back(n2);
			out_degree[n1]++, in_degree[n2]++;
		}
	}
	//find Eulerian path
    adj[n].emplace_back(1);
    out_degree[n]++, in_degree[1]++;
}
 
bool find_Euler_circuit(int mode, int n, int m){
	if(mode == DIRECTOR_GRAPH){
		init(mode, n, m);
		for(int i=1;i<=n;i++){
			if(in_degree[i] != out_degree[i]){
				return false;
			}
		}
        dfs(1);
		for(int i=1;i<=n;i++){
			if(in_degree[i] != 0 && out_degree[i] != 0){
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
	if(find_Euler_circuit(DIRECTOR_GRAPH, n, m)){
		reverse(circuit.begin(), circuit.end());
        circuit.pop_back();
        int first = 0;
        for(int i=1;i<circuit.size();i++){
            if(circuit[i-1] == n && circuit[i] == 1){
                first = i;
            }
        }
        vector<int> path;
        for(int i=first;i<circuit.size();i++){
            path.emplace_back(circuit[i]);
        }
        for(int i=0;i<first;i++){
            path.emplace_back(circuit[i]);
        }
        for(const int& c:path){
			cout<<c<<" ";
		}
		cout<<'\n';
	}else{
		cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
