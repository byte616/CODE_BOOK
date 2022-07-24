#include<bits/stdc++.h>
using namespace std;
int n,m,maps[1005][1005],a,b,x,y;
char c;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c;
            if(c=='*')maps[i][j]=1;
            maps[i][j]+=maps[i-1][j]+maps[i][j-1]-maps[i-1][j-1];
        }
    }
    while(m--){
        cin>>x>>y>>a>>b;
        cout<<maps[a][b]-maps[x-1][b]-maps[a][y-1]+maps[x-1][y-1]<<'\n';
    }
}