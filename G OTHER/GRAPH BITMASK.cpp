#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define ar array
template <class T,class S> inline bool chmin(T &a,const S &b) {return (a> b? a= b, 1: 0);}
template <class T,class S> inline bool chmax(T &a,const S &b) {return (a< b? a= b, 1: 0);}
const int mxn= 20,mod= 1e9+ 7;
int main(){
    int n,m;
    cin>> n>> m;
    vector <int> adj[n];
    for(int i= 0,a,b;i< m;i++){
        cin>> a>> b;--a,--b;
        adj[a].push_back(b);
    }
    vector <vector<ll>> dp(mxn,vector<ll>(1<< mxn,0)); // [end at city i ,subset]
    dp[0][1]= 1;
    for(int s= 0;s< 1<< n;s++){
        if(s>> (n- 1) & 1 && s!= (1<< n)- 1) continue;
        for(int i= 0;i< n;i++){
            if(s>> i & 1){
                for(auto ele: adj[i]){
                    if(s>> ele & 1) continue;
                    int j= s ^ (1<< ele);
                    dp[ele][j]= (dp[ele][j]+ dp[i][s]) % mod;
                }
            }
        }
    }
    cout<< dp[n- 1][(1<< n)- 1]<<"\n";
}