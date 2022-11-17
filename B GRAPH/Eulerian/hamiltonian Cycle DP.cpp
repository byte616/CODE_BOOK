//O(n * 2^n)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
vector<vector<int>> adj;
const int MOD = 1000000007;
long long way[(1<<21) + 5][25];
bool vis[(1<<21)][25];
bool flag = true;
int n;
 
inline void bfs(){
    queue<pair<int, int>> qu;
    way[1][0] = 1;
    qu.emplace(0, 1);
    vis[1][0] = 1;
    int node, visit;
    while(!qu.empty()){
        node = qu.front().first;
        visit = qu.front().second;
        qu.pop();
        //if(vis[visit][node])continue;
        //cout<<"node "<<node<<", visit "<<visit<<endl;
        for(int e:adj[node]){
            if((visit & (1<<e)) == 0){
                //unvisited
                way[visit | (1<<e)][e] += way[visit][node];
                if(way[visit | (1<<e)][e] >= MOD)   way[visit | (1<<e)][e] %= MOD;
                if(!vis[visit | (1<<e)][e] && e != n-1){
                    qu.emplace(e, visit | (1<<e));
                    vis[visit|(1<<e)][e] = true;
                }
            }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>n>>m;
    adj.resize(n+5);
    for(int i=0, a, b;i<m;i++){
        cin>>a>>b;
        a--, b--;
        if(a == b)continue;
        adj[a].emplace_back(b);
    }
    bfs();
    //for(int i=0;i<n;i++){
    //    for(int j=0;j<(1<<n);j++){
    //        cout<<way[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
 
    cout<<way[(1<<n)-1][n-1]<<endl;
    return 0;
}

