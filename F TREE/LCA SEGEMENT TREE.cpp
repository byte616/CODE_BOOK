#include<iostream>
#include<vector>
using namespace std;
#define INF 100000008
#define maxSize 200005
#define root 1
 
int deep[maxSize];
int visidx[maxSize];
vector<int> way;
vector< vector<int> > adj;
struct Node{
    int L, R;
    int val;
    int id;
}tree[maxSize*8];
 
void build(int idx, int L, int R){
    tree[idx].L = L;
    tree[idx].R = R;
    if(L == R){
        tree[idx].val = deep[way[L]];
        tree[idx].id = L;
        return;
    }
    int mid = (L + R)/2;
    build(idx*2, L, mid);
    build(idx*2+1, mid+1, R);
    if(tree[idx*2].val > tree[idx*2+1].val){
        tree[idx].val = tree[idx*2+1].val;
        tree[idx].id = tree[idx*2+1].id;
    }else{
        tree[idx].val = tree[idx*2].val;
        tree[idx].id = tree[idx*2].id;
    }
}
 
int query(int idx, int qL, int qR){
    //cout<<idx<<" "<<tree[idx].L<<" "<<tree[idx].R<<" "<<tree[idx].id<<endl;
    if(qL > tree[idx].R || qR < tree[idx].L){return -1;}
    else if(tree[idx].L >= qL && tree[idx].R <= qR){
        return tree[idx].id;
    }
    int id1 = query(idx*2, qL, qR);
    int id2 = query(idx*2+1, qL, qR);
    if(id1 == -1){
        return id2;
    }else if(id2 == -1){
        return id1;
    }else{
        if(deep[way[id1]] < deep[way[id2]]){
            return id1;
        }else{
            return id2;
        }
    }
}
 
void DFS(int node){
    visidx[node] = way.size();
    way.push_back(node);
    for(int u:adj[node]){
        deep[u] = deep[node]+1;
        DFS(u);
        way.push_back(node);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    adj.resize(n+5);
    int x;
    for(int i=2;i<=n;i++){
        cin>>x;
        adj[x].push_back(i);
    }
    deep[root] = 1;
    DFS(root);
    build(1, 0, way.size()-1);
    int a, b, sum;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(visidx[a] > visidx[b]) swap(a, b);
        int ans = query(1, visidx[a], visidx[b]);
        //" "<<deep[a] + deep[b] - 2*deep[way[ans]]
        cout<<way[ans]<<'\n';
    }
    return 0;
}
