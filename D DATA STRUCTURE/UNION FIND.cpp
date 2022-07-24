int pa[MAX_N];
int find(in x){
    return pa[x]==x ? x : pa[x]=find(pa[x]);
}
bool uni(int a,int b){
    int _a=find(a),_b=find(b);
    if(_a==_b)return 0;
    pa[_b]=_a;
    return 1;
}