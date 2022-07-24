const int mxn= 5005;
ll dp[mxn][mxn]= {};
main(){
    int n;
    cin>> n;
    vector <int> arr(n);
    for(auto &ele: arr) cin>> ele;
    for(int i= n- 1;~i;i--){
        for(int j= i;j< n;j++){
            if(i ^ j)
                dp[i][j]= max(arr[i]- dp[i+ 1][j],arr[j]- dp[i][j- 1]);
            else 
                dp[i][j]= arr[i];
        }
    }
    cout<< (accumulate(all(arr),0LL)+ dp[0][n- 1])/ 2<<"\n";
}