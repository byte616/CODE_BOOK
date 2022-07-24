#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset= tree<T ,null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
int main(){
    int n,k;
    cin>> n>> k;
    oset<int> os;
    for(int i= 1;i<= n;i++)
        os.insert(i);
    int p= k % n;
    while(!os.empty()){
        int r= *os.find_by_order(p);
        os.erase(r);
        if(!os.empty())
            p= (p+ k)% os.size();
        cout<< r<<" ";
    }    
    cout<<"\n";
}