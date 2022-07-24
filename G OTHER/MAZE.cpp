#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define ar array
template <class T,class S> inline bool chmin(T &a,const S &b) {return (a> b? a= b, 1: 0);}
template <class T,class S> inline bool chmax(T &a,const S &b) {return (a< b? a= b, 1: 0);}
const int mxn= 1e3+ 5;
const int di[4]= {0,1,0,-1},dj[4]= {1,0,-1,0};
const string dc= "RDLU";
int main(){
    int n,m;
    cin>> n>> m;
    char s[mxn][mxn];
    int pre[mxn][mxn];
    auto ok= [&](int i,int j)-> bool{
        return i>= 0 && i< n && j>= 0 && j< m && s[i][j] == '.';
    };

    auto e= [&](int i,int j)-> bool{
        return i>= 0 && i< n && j>= 0 && j< m && s[i][j] == 'B';
    };
    ar<int,2> A;
    queue<ar<int,2>> q;
    for(int i= 0;i< n;i++){
        for(int j= 0;j< m;j++){
            cin>> s[i][j];
            if(s[i][j] == 'A'){
                A= {i,j};
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto [i,j]= q.front();q.pop();
        for(int k= 0;k< 4;k++){
            int ni= i+ di[k], nj= j+ dj[k];
            if(e(ni,nj)){
                string ans;
                pre[ni][nj]= k;
                while(ar<int,2> {ni,nj}!= A){
                    int p= pre[ni][nj];
                    ni-= di[p];
                    nj-= dj[p];
                    ans+= dc[p];
                }
                reverse(all(ans));
                cout<< "YES"<<"\n"<< ans.size()<<"\n"<< ans<<"\n";
                return 0;
            }
            if(ok(ni,nj)){
                pre[ni][nj]= k;
                q.push({ni,nj});
                s[ni][nj]= '*';
            }
        }
    }
    cout<< "NO"<<"\n";
}