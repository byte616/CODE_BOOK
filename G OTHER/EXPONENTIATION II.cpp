#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll p=1000000007;
ll t,a,b,c;
ll fp(ll a,ll b,ll p){
    ll res=1;
    while(b){
        if(b&1)res=res*a%p;
        b>>=1;
        a=a*a%p;
    }
    return res;
}
int main(){
    // find a^(b^c)
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cout<<fp(a,fp(b,c,p-1),p)<<'\n';
    }
}