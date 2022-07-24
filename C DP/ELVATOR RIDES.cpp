main(){
    int n,x;
    cin>> n>> x;
    vector <int> arr(n); for(auto &ele: arr) cin>> ele;
    vector <ar<int,2>> dp(1<< n,{n,0});
    dp[0]= {1,0};
    for(int m= 1;m< 1<< n;m++){
        for(int i= 0;i< n;i++){
            if(m>> i & 1){
                auto [a,b]= dp[m ^ (1<< i)];
                if(b + arr[i]> x){
                    a++;
                    b= arr[i];
                }
                else 
                    b= b+ arr[i];
                chmin(dp[m],ar<int,2> {a,b});
            }
        }
    }
    cout<< dp.back()[0]<<"\n";
}