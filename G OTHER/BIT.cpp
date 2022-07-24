#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define ar array
template <class T,class S> inline bool chmin(T &a,const S &b) {return (a> b? a= b, 1: 0);}
template <class T,class S> inline bool chmax(T &a,const S &b) {return (a< b? a= b, 1: 0);}
struct BIT{
    int n;
    vector<ll> tree;
    BIT (int n): n(n),tree(n+ 1){}
    void add(int x,ll val){
        while(x<= n){
            tree[x]+= val;
            x+= x & -x;
        }
    }
    void upd(int l,int r,ll val){
        add(l,val);
        add(r+ 1,-val);
    }
    ll sum(int x){
        ll res= 0;
        while(x){
            res+= tree[x];
            x-= x& -x;
        }
        return res;
    }
};
int main(){
    int n,q;
    cin>> n>> q;
    BIT bit(n);
    for(int i= 1,a;i<= n;i++){
        cin>> a;
        bit.upd(i,i,a);
    }
    while(q--){
        int ts;
        cin>> ts;
        if(ts & 1){
            int l,r,val;
            cin>> l>> r>> val;
            bit.upd(l,r,val);
        }else{
            int pos;
            cin>> pos;
            cout<< bit.sum(pos)<<"\n";
        }
    }
}