const int mxx= 1e5+ 5;
int dp[mxx];
main(){
    int n;
    cin>> n;
    vector<int> c(n);
    for(auto &ele: c)
        cin>> ele;
    dp[0]= 1;
    for(auto ele: c){
        for(int i= mxx;i;i--)
            if(i- ele>= 0)
                dp[i]|= dp[i- ele];
    }
    vector<int> ans;
    for(int i= 1;i<= mxx;i++)
        if(dp[i]) ans.push_back(i);
    cout<< ans.size()<<"\n";
    for(auto ele: ans)
        cout<< ele<<" ";
    cout<<"\n";
}