// O(N) to find Eulerian circuit
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define f first
#define s second

int n, m, a, b, deg[100005];
vector<pii> v[100005]; // node : edge index
vector<int> ans;
bool vis[200005]; // edge 

void dfs(int x) {
	while(!v[x].empty()) {
		pii u = v[x].back();
		v[x].pop_back();
		if(!vis[u.s]) {
			vis[u.s] = 1;
			dfs(u.f);
			ans.push_back(u.f);
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		deg[a] += 1;
		deg[b] += 1;
		v[a].push_back({b, i});
		v[b].push_back({a, i});
	}

	for(int i = 1; i <= n; i++) {
		if(deg[i] & 1) {
			cout << "IMPOSSIBLE" << '\n';
			return 0;
		}
	}

	dfs(1);
	ans.push_back(1);
	if(ans.size() != m + 1) {
		cout << "IMPOSSIBLE" << '\n';
	}
	else {
		for(auto i : ans) {
			cout << i << " ";
		}
	}

}

 
