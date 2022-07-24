#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// a -> b  weight:w
struct edge{
    ll a,b,w;
    int use;
};
bool cmp(edge a,edge b){
    if(a.w!=b.w)return a.w<b.w;
    return a.use<b.use;
}
ll n,m,a,b,c,pa[200005];
// find
int root(int x){
    return pa[x]==x ?x :pa[x]=root(pa[x]);
}
// union
bool uni(ll a,ll b){
    ll r1=root(a),r2=root(b);
    if(r1==r2)return 0;
    pa[r2]=r1;
    return 1;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    vector<edge>v;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v.push_back({a,b,c,0});
    }
    // init parent 
    for(int i=0;i<=n;i++)pa[i]=i;
    //sort the edge
    sort(v.begin(),v.end(),cmp);
    ll cnt=n-1,ans=0;
    // run all the road
    for(auto &i:v){
        // check union or  not
        // union -> 0
        // not union ->1
        if(uni(i.a,i.b)){
            i.use=1;
            ans+=i.w; 
            cnt--;
            if(!cnt)break; // finish
        }
    }
    sort(v.begin(),v.end(),cmp);
    ll ans2=0,cnt2=n-1;
    for(int i=0;i<=n;i++)pa[i]=i;
    for(auto &i:v){
        // check union or  not
        // union -> 0
        // not union ->1
        if(uni(i.a,i.b)){
            i.use=1;
            ans2+=i.w; 
            cnt2--;
            if(!cnt2)break; // finish
        }
    }
    cout<<ans<<'\n';
    if(ans2==ans){
        int sum=0;
        for(auto i:v)if(i.use)sum++;
        if(sum>n-1)cout<<"NO\n";
        else cout<<"YES\n";
    }
    else cout<<"YES\n";
}