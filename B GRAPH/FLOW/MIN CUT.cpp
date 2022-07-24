void add_edge(int a,int b){
    v[a].push_back(edge(b,1,v[b].size()));
    v[b].push_back(edge(a,0,v[a].size()-1));
}
main(){
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        add_edge(a,b);
        add_edge(b,a);
    }
    cout<<max_flow();
}
