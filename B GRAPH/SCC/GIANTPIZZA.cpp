#include<iostream>
#include<vector>
using namespace std;
 
 
 
const bool FIRST_DFS = 1;
const bool SECOND_DFS = 0;
int team = 0;
vector<int> path;
bool vis[200005];
int group[200005];
vector<vector<int>> group_list;
 
 
 
 
void dfs(int node, vector<vector<int>> &g, bool mode){
    if(vis[node]) return;
    vis[node] = true;
    for(int &e:g[node]){
        dfs(e, g, mode);
    }
    if(mode == FIRST_DFS){
        path.push_back(node);
    }else{
        group[node] = team;
    }
}
 
void Kosaraju(vector<vector<int>> g, vector<vector<int>> gc, int s, int t){
    //g is adjcent list graph
    //gc is g with reverse edge
    //s is the start node, t is terminal start
    path.clear();
    for(int i=s;i<=t;i++){
        vis[i] = 0;
    }
    for(int i=s;i<=t;i++){
        if(vis[i])continue;
        dfs(i, g, FIRST_DFS);
    }
    for(int i=s;i<=t;i++){
        vis[i] = 0;
    }
    for(int i = path.size()-1;i>=0;i--){
        if(vis[path[i]])continue;
        team++;                // how many strong connect component
        dfs(path[i], gc, SECOND_DFS);    // fill team number
    }
}
 
 
vector<vector<int>> adj, adjc;
int ans[200005];
 
int inv(int c){
	if(c % 2 == 0){
		return c - 1;
	}
	return c + 1;
}
 
void ans_dfs(int node, const vector<vector<int>>& g){
	if(vis[node])	return;
	vis[node] = true;
	for(const int& e: g[node]){
		if(group[e] == group[node])	continue;
		ans_dfs(e, g);
	}
	for(const int& e: g[node]){
		if(group[e] != group[node])	continue;
		ans_dfs(e, g);
	}
	if(ans[group[node]] == 0){
		ans[group[node]] = 1;
		ans[group[inv(node)]] = 2;
	}
}
 
 
// - 1 --> 1
// + 1 --> 2
// - x --> 2 * x - 1
// + x --> 2 * x
 
 
int main(){
	int n, m;
	cin>>n>>m;
	adj.resize(m*2+10);
	adjc.resize(m*2+10);
	char c, d;
	for(int i=0, x, y, xc, yc;i<n;i++){
		cin>>c>>x>>d>>y;
		if(x == y){
			if(c == d){
				// x or x
				x = 2 * x - (c == '-');
				xc = x + (c == '-' ? 1 : -1);	//x's complment
				adj[xc].push_back(x);
				adjc[x].push_back(xc);
			}//else x or -x --> do nothing
			continue;
		}
		x = 2 * x - (c == '-');
		xc = x + (c == '-' ? 1 : -1);	//x's complment
		y = 2 * y - (d == '-');
		yc = y + (d == '-' ? 1 : -1);	// y's complment
		adj[xc].push_back(y);
		adj[yc].push_back(x);
		adjc[y].push_back(xc);
		adjc[x].push_back(yc);
	}
	/*for(int i=1;i<=2*m;i++){
			cout<<i<<" : ";
			for(const int& e:adj[i]){
				cout<<e<<" ";
			}
			cout<<'\n';
	}*/
	Kosaraju(adj, adjc, 1, 2*m);
	bool flag = true;
	
	//check x and x' in same group or not
	/*for(int i=1;i<=2*m;i++){
		cout<<group[i]<<" ";
	}
	cout<<'\n';*/
	for(int i=2;i<=2*m;i+=2){
		if(group[i] == group[i-1]){
			flag = false;
		}
	}
	
	if(flag){
		path.clear();
		for(int i=0;i<=2*m;i++){
			vis[i] = 0;
		}
		for(int i=1;i<=2*m;i++){
			if(!vis[i])	ans_dfs(i, adj);
		}
		for(const int& e:path){
			if(ans[group[e]] == 0){
				ans[group[e]] = 1;
				ans[group[inv(e)]] = 2;
			}
		}
		for(int i=1;i<2*m;i+=2){
			if(ans[group[i]] == 1){
				cout<<'-';
			}else{
				cout<<'+';
			}
			cout<<" ";
		}
		cout<<'\n';
	}else{
		cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
