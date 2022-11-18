#include<iostream>
#include<vector>
using namespace std;

struct Edge{
    int from, to;
    long long wei;
    Edge(int _from, int _to, long long _wei)
        :from(_from), to(_to), wei(_wei){};
};


int need[30], can_use[30];
const int INF = 0x3f3f3f3f;
vector<Edge> edges;
void add_equation(int node1, int node2, int wei){
    //node1 - node2 > wei
    edges.emplace_back(node2, node1, -wei);
}


bool bellman_ford(){
    //cout<<"bellman_ford()"<<endl;
    int n = 25;
    vector<long long> dis(30, INF);
    dis[0] = 0;
    for(int i=0;i<=n;i++){
        for(const Edge &e:edges){
            if(dis[e.to] > dis[e.from] + e.wei){
                dis[e.to] = dis[e.from] + e.wei;
                if(i == n)  return false;
            }
        }
    }
    return true;
}


bool difference_constraint(int ans){
    edges.clear();
    // S[t] - S[t-1] >= 0           for t >= 1
    for(int t=1;t<=24;t++){
        add_equation(t, t-1, 0);
    }
    // S[t-1] - S[t] >= -can_use[t] for t >= 1
    for(int t=1;t<=24;t++){
        add_equation(t-1, t, -can_use[t]);
    }
    // S[t] - S[t-8] >= need[t] for t >= 9
    for(int t = 9;t <= 24;t++){
        add_equation(t, t-8, need[t]);
    }
    // S[t] - S[t+16] >= need[t] - S[24] for t < 9
    for(int t = 1;t < 9;t++){
        add_equation(t, t+16, need[t] - ans);
    }

    //S[24] >= ans -> S[24] - S[0] >= ans
    add_equation(24, 0, ans);
    return bellman_ford();
}




int main(){
    int T;
    cin>>T;
    while(T--){
        for(int i=1;i<=24;i++){
            cin>>need[i];
            can_use[i] = 0;
        }
        int emp;
        cin>>emp;
        for(int i=0, x;i < emp;i++){
            cin>>x;
            x++;
            can_use[x]++;
        }
        bool flag = false;
        for(int ans=0;ans <= emp;ans++){
            if(difference_constraint(ans)){
                cout<<ans<<'\n';
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<"No Solution\n";
        }
    }
    return 0;
}

//Equations
//令 X[t] 為在時間 t 實際雇用的人數
//令 S[t] 為 X[t] 的前綴和
// S[t] - S[t-1] >= 0           for t >= 1
// S[t-1] - S[t] >= -can_use[t] for t >= 1
// S[t] - S[t-8] >= need[t] for t >= 9
// S[t] - S[t+16] >= need[t] - S[24] for t < 9
//use brute force to search S[24]
