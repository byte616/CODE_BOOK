const int N=1e6;
vector<ll>v;
vector<int>flag(N,1);
void is_prime(){
    flag[0]=flag[1]=0;
    for(int i=2;i<N;i++){
        if(flag[i]){
            v.push_back(i);
            for(long long int j=i*i;j<N;j+=i)flag[j]=0;
        }
    }
}