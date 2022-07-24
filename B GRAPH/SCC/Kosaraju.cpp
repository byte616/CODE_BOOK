#include<iostream>
#include<vector>
using namespace std;
 
const bool FIRST_DFS = 1;
const bool SECOND_DFS = 0;
int team = 0;
vector<int> path;
bool vis[100005];
int group[100005];
 
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
 
 
int main(){
    vector<vector<int>> g, gc;
    int n, m;
    cin>>n>>m;
    g.resize(n+5);
    gc.resize(n+5);
    for(int i=0, x, y;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y);
        gc[y].push_back(x);
    }
    Kosaraju(g, gc, 1, n);
    cout<<team<<'\n';
    for(int i=1;i<=n;i++){
        cout<<group[i]<<" ";
    }
    cout<<'\n';
    return 0;
}

