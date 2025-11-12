// O(n)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, a, b, ans[100005], team;
vector<int> v[100005], rv[100005], path;
bool vis1[100005], vis2[100005];

void dfs(int x) {
	vis1[x] = 1;
	for(auto i : v[x]) {
		if(!vis1[i]) dfs(i);
	}
	path.push_back(x);
}

void dfs2(int x) {
	vis2[x] = 1;
	ans[x] = team;
	for(auto i : rv[x]) {
		if(!vis2[i]) dfs2(i);
	}
}

int main() {
	cin >> n >> m;
	while(m--) {
		cin >> a >> b;
		v[a].push_back(b);
		rv[b].push_back(a);
	}

	for(int i = 1; i <= n; i++) {
		if(!vis1[i]) {
			dfs(i);
		}
	}

	reverse(path.begin(), path.end());
	for(auto i : path) {
		if(!vis2[i]) {
			team += 1;
			dfs2(i);
		}
	}

	cout << team << '\n';
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}
