/*
    dp 優化技巧： divide and conquer
    cost function 須滿足 cost(a, c) + cost(b, d) <= cost(a, d) + cost(b, c)
    亦即，我現在選擇用 p 來轉移，則我前面的人的選擇絕對不會大於 p；而我後面的人的選擇也絕對不會小於 p
    O(n*n*k) -> O(n*klongn)
*/
#include<iostream>
using namespace std;
 
const long long INF = (long long)1e16;
long long dp[3003][3003];
int p[3003][3003];
long long prefix[3003], a[3003];
 
long long cost(const int &i, const int &j){
    long long tmp = prefix[j] - prefix[i-1];
    //cout<<"cost("<<i<<", "<<j<<") = "<<tmp * tmp<<endl;
    return tmp * tmp;
}
 
long long solve(const int &i, const int &j, const int &pL, const int &pR){
    // 考慮前 i 個數字，切成 j 塊的最小 cost，並且保證只需要在 (pL, pR) 間取 min 就可以了
    if(p[i][j] != -1){
        return p[i][j];
    }
    dp[i][j] = dp[i-1][j-1] + cost(i, i);
    p[i][j] = i;
    for(int r = pL;r<=pR;r++){
        long long tmp = dp[r-1][j-1] + cost(r, i);
        if(tmp < dp[i][j]){
            p[i][j] = r;
            dp[i][j] = tmp;
        }
    }
    return p[i][j];
}
 
 
void calcu(int j, int L, int R, int pL, int pR){
    // 計算切成 j 塊下，前 L 個數字到前 R 個數字的 dp[i][j]，並且保證只需要在 pL 至 pR 之間取 min 即可
    if(L > R){
        return;
    }
    // 先計算中間那個點的 dp[mid][j]
    int mid = (L+R) / 2;
    int midp = solve(mid, j, pL, pR);
    calcu(j, L, mid-1, pL, midp);
    calcu(j, mid+1, R, midp, pR);
}
 
 
int main(){
    int n, k;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            p[i][j] = -1;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][0] = INF;
        prefix[i] = prefix[i-1] + a[i];
    }
    for(int i=1;i<=k;i++){
        dp[0][i] = INF;
    }
    dp[0][0] = 0;
    /* original dp
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = INF;
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + cost(i, i));
            for(int r = 1;r <=i;r++){
               dp[i][j] = min(dp[i][j], dp[r-1][j-1] + cost(r, i)); 
            }
        }
    }
    */
	// optimized dp
    for(int j=1;j<=k;j++){
        calcu(j, 1, n, 1, n);
    }
    cout<<dp[n][k]<<endl;
    return 0;
}
