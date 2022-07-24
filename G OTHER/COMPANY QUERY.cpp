#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,p[20][200005];
int main(){
    cin>>n>>m;
    for(int i=2;i<=n;i++)cin>>p[0][i]; // input their parent
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
    while(m--){
        cin>>a>>b;// ask a's b higher position
        for(int i=0;i<20;i++){
            if(b&(1<<i))a=p[i][a];
        }
        cout<<(!a?-1:a)<<'\n';
    }
}