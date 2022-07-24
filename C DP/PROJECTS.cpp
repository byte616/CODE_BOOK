main(){
    int n;
    cin>> n;
    vector <ar<int,3>> arr(n);
    for(auto &[a,b,c]: arr) cin>> b>> a>> c;
    sort(all(arr));
    vector <ll> dp(n);
    dp[0]= arr[0][2];
    for(int i= 1;i< n;i++){
        auto [r,l,v]= arr[i];
        int p= lower_bound(all(arr),ar<int,3> {l,-87,-7414})- arr.begin()- 1;
        if(~p)
            dp[i]= max(dp[i- 1],dp[p]+ v);
        else 
            dp[i]= max(dp[i- 1],(ll)v);
    }
    cout<< *dp.rbegin()<<"\n";
}