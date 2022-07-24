#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define ar array
#define all(x) x.begin(),x.end()
template<class T> using oset= tree<T ,null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
int main(){
    int n;
    cin>> n;
    vector <ar<int,3>> arr(n);
    for(int i= 0,l,r;i< n;i++){
        cin>> l>> r;
        arr[i]= {l,r,i};
    }
    // Range [a,b] contains range [c,d] if a≤c and d≤b.
    auto cmp= [](ar<int,3> a, ar<int,3> b)-> bool{
        return a[0]== b[0]? a[1]> b[1]: a[0]< b[0];
    };
    // Sort the range greatest<>
    sort(all(arr),cmp);
    vector <int> ans1(n),ans2(n);
    oset<ar<int,2>> os1,os2;
    for(int i= 0,j= n- 1;i< n;i++,j--){
        ans1[arr[j][2]]= os1.order_of_key({arr[j][1]+ 1,-878787});
        ans2[arr[i][2]]= i- os2.order_of_key({arr[i][1],-74147414});
        os1.insert({arr[j][1],j});
        os2.insert({arr[i][1],i});
    }
    for(auto ele: ans1)
        cout<< (ele? 1: 0)<< " ";
    cout<<"\n";
    for(auto ele: ans2)
        cout<< (ele? 1: 0)<< " ";
    cout<<"\n";
    
}