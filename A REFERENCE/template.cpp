#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define ar array
template <class T,class S> inline bool chmin(T &a,const S &b) {return (a> b? a= b, 1: 0);}
template <class T,class S> inline bool chmax(T &a,const S &b) {return (a< b? a= b, 1: 0);}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    return 0;
}

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T> using oset= tree<T ,null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;