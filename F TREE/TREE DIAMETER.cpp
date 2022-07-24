int mx[MAX_N],idx[MAX_N];
vector<int>v[MAX_N];
void find_far(int x,int pre){
    idx[x]=x;
    mx[x]=0;
    for(auto i:v[x]){
        if(i==pre)continue;
        find_far(k,x);
        if(mx[i]+1>mx[x]){
            mx[x]=mx[i]+1;
            idx[x]=idx[i];
        }
    }
}
main(){
    add_edge();// both side
    find_far(1,0);
    int root=idx[1];
    find_far(root,0);
    cout<<mx[root];
}