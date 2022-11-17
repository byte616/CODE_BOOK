// O(N)

vector<vector<int>> v;
int D[100005], L[100005];
int time_stamp = 0;
vector<int> ans_AP;
vector<pair<int, int>>ans_bridge;

void DFS(int node, int par){
    D[node] = L[node] = ++time_stamp;
    int child_cnt = 0;
    bool is_AP = false;
    for(const int& e:v[node]){
        if(e == par){continue;}
        if(D[e] == 0){
            child_cnt++;
            DFS(e, node);
            if(D[node] <= L[e]){is_AP = true;}// point
            if(D[node] < L[e]){ans_bridge.push_back({e, node});}// bridge
            L[node] = min(L[node], L[e]);
        }else{
            // back edge
            L[node] = min(D[e], L[node]);
        }
    }
    if(par == 0){is_AP = child_cnt >=2;}// root is special case
    if(is_AP){
        ans_AP.push_back(node);
    }
}
