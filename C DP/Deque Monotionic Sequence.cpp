// DP 單調隊列優化
// O(N) 找所有長度為 k 的 sliding window 的最小值

const int MAX_N = 1e6+5;
int a[MAX_N];

int main(){
        deque<pair<int, int>> mi;
        vector<int> ans_min;
        for(int i=0;i<n;i++){
                if(mi.front().second == i-k){
                        mi.pop_front();
                }
                while(!mi.empty() && mi.back().first >= a[i]){
                        mi.pop_back();
                }
                mi.emplace_back(a[i], i);
                if(i >= k-1)    ans_min.push_back(mi.front().first);
        }
        if(k > n){
                ans_min.push_back(mi.front().first);
        }
    return 0;
}
