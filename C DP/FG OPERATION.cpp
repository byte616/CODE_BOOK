//2^n-1 OPERATION 
//ACCUMULATION SUM
main(){
    cin>> n;
    vector <int> arr(n);
    for(auto &ele: arr)
        cin>> ele;
    ll dp[n][10] = {};
    dp[0][arr[0]] = 1;
    for(int i= 1;i< n;i++){
        for(int j = 0;j< 10;j++){
            dp[i][(j + arr[i])] += dp[i - 1][j];
            dp[i][j * arr[i]] += dp[i - 1][j];
        }
    }
    for(auto ele: dp[n- 1])cout<< ele<<"\n";
}