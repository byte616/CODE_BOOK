#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
 
struct query{
    int idx, L, R;
};
 
int block;
 
bool cmp(const query &a, const query &b){
    if(a.L/block != b.L/block){
        return a.L < b.L;
    }
    /*if(a.R != b.R){
        return a.R < b.R;
    }*/
    return a.R < b.R;
}
 
vector<int> v;
int a[200005];
int coun[200005];
int ans[200005];
query q[200005];
 
int bs(int value){
    int left = -1, right = v.size(), mid;
    while(right - left > 1){
        mid = (left+right)/2;
        if(v[mid] < value){left = mid;}
        else{right = mid;}
    }
    return left+1;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    block = sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int i = 0;
    for(int j=1;j<n;j++){
        if(v[j-1]!=v[j]){i++;}
        v[i] = v[j];
    }
    v.resize(i+1);
    for(int i=1;i<=n;i++){
        a[i] = bs(a[i]);
    }
    for(int i=0;i<m;i++){
        cin>>q[i].L>>q[i].R;
        q[i].idx = i;
    }
    sort(q, q+m, cmp);
    int sum = 0;
    query now = q[0];
    for(int i=now.L;i<=now.R;i++){
        coun[a[i]]++;
        if(coun[a[i]] == 1){sum++;}
    }
    ans[now.idx] = sum;
    for(int i=1;i<m;i++){
        //cout<<"L = "<<q[i].L<<", R ="<<q[i].R<<" ";
        while(now.L > q[i].L){
            now.L--;
            coun[a[now.L]]++;
            if(coun[a[now.L]] == 1){sum++;}
        }
        while(now.L < q[i].L){
            coun[a[now.L]]--;
            //cout<<endl<<"a[now.L] "<<a[now.L]<<" "<<coun[a[now.L]]<<endl;
            if(coun[a[now.L]] == 0){sum--;}
            now.L++;
        }
        while(now.R > q[i].R){
            coun[a[now.R]]--;
            //cout<<"a[now.R] = "<<a[now.R]<<" "<<coun[a[now.R]]<<endl;
            if(coun[a[now.R]] == 0){sum--;}
            now.R--;
        }
        while(now.R < q[i].R){
            now.R++;
            coun[a[now.R]]++;
            if(coun[a[now.R]] == 1){sum++;}
        }
        //cout<<coun.size()<<endl;
        ans[q[i].idx] = sum;
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<'\n';
    }
 
    return 0;
}
