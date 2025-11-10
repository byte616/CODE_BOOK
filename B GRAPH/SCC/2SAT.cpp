// 2SAT --> SCC
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// one node has pos & neg --> 2 times of size
int n, m, x, y, teams[200005], cnt;
char c1, c2;
vector<int> v[200005], rv[200005], path;
vector<char> ans;
bool vis1[200005], vis2[200005];

int rev(int x) {
	if(x <= m) return x + m;
	return x - m;
}

void dfs(int x) {
	vis1[x] = 1;
	for(auto i : v[x]) {
		if(!vis1[i]) dfs(i);
	}
	path.push_back(x);
}

void dfs2(int x) {
	vis2[x] = 1;
	teams[x] = cnt;
	for(auto i : rv[x]) {
		if(!vis2[i]) dfs2(i);
	}
}

int main() {
	cin >> n >> m;
	// pos: 1 ~ m, neg: m + 1 ~ 2m
	for(int i = 1; i <= n; i++) {
		// + means pos, - means negative
		cin >> c1 >> x >> c2 >> y;
		if(c1 == '-') x += m;
		if(c2 == '-') y += m;
		
		// edge: rev(a) --> b, rev(b) --> a
		v[rev(x)].push_back(y);
		v[rev(y)].push_back(x);

		// reverse edge
		rv[y].push_back(rev(x));
		rv[x].push_back(rev(y));
	}

	// be careful about 2m
	for(int i = 1; i <= m * 2; i++) {
		if(!vis1[i]) dfs(i);
	}
	reverse(path.begin(), path.end());
	for(auto i : path) {
		if(!vis2[i]) {
			cnt += 1;
			dfs2(i);
		}
	}

	// if teams[i] == teams[i + m] 
	// --> no solution (pos & neg in the same group)
	for(int i = 1; i <= m; i++) {
		if(teams[i] == teams[i + m]) {
			cout << "IMPOSSIBLE" << '\n';
			return 0;
		}
		if(teams[i] > teams[i + m]) {
			ans.push_back('+');
		}
		else ans.push_back('-');
	}
	for(auto i : ans) {
		cout << i << " ";
	}
	return 0;
}

