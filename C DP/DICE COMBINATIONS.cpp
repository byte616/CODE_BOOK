main(){
    int n;
    cin>> n;
    int dp[n+ 5]= {};
    dp[0]= 1;
    for(int i= 0;i< n;i++){
        for(int j= 1;j<= 6;j++)
            if(i+ j<= n)
                dp[i+ j]= (dp[i+ j]+ dp[i]) % mod;
    }
    cout<< dp[n]<<"\n";
}