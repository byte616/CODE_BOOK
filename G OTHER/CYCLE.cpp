#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define ar array
template <class T,class S> inline bool chmin(T &a,const S &b) {return (a> b? a= b, 1: 0);}
template <class T,class S> inline bool chmax(T &a,const S &b) {return (a< b? a= b, 1: 0);}
const int mxn= 2e5;
vector <vector<int>> adj(mxn);
vector <bool> ok(mxn,false);
int main(){
    int n,m;
    cin>> n>> m;
    for(int i= 0,a,b;i< m;i++){
        cin>> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector <int> ans,par(mxn,-1);
    auto dfs= [&](auto &&f,int u,int pr= -1)-> void{
        ok[u]= true;
        par[u]= pr;
        for(auto ele: adj[u]){
            if(ele== pr) continue;

            if(ok[ele]){
                int x= u;
                while(u^ ele){
                    ans.push_back(u);
                    u= par[u];
                }
                ans.push_back(ele);
                ans.push_back(x);
                cout<< ans.size()<<"\n";
                for(auto elee: ans)
                    cout<< elee<<' ';
                cout<<"\n";

                exit(0);
            }
            else 
                f(f,ele,u);
        }
    };
    for(int i= 1;i<= n;i++)
        if(!ok[i]) dfs(dfs,i);

    cout<< "IMPOSSIBLE"<<"\n";
}