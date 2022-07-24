main(){
    for(int i=1;i<=n;i++)cin>>yes[i];
    for(int i=2;i<=n;i++){
        no[i]=max(no[i-1],yes[i-1]);
        yes[i]+=no[i-1];
    }
    cout<<max(yes[n],no[n])<<'\n';
}