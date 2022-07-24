main(){
    int n;
    cin>> n;
    string s[n];
    for(auto &ele: s)
        cin>> ele;
    int dp[n+ 5][n+ 5]={};
    dp[0][0]= 1;
    for(int i= 0;i< n;i++){
        for(int j= 0;j< n;j++){
            if(i) dp[i][j]+= dp[i- 1][j];
            if(j) dp[i][j]+= dp[i][j- 1];
            dp[i][j]%= mod;
            if(s[i][j]== '*') dp[i][j]= 0;
        }
    }
    cout<< dp[n- 1][n- 1]<<"\n"; 
}