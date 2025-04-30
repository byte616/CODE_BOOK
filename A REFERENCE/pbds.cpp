#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*
#include <bits/extc++.h>
*/
using namespace __gnu_pbds;
using namespace std;
int main()
{
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistics_node_update> tr;
    int a = 1;
    int k;
    cin >> k;
    tr.insert(a);
    tr.erase(a);
    tr.lower_bound(a);
    tr.find_by_order(k); // an iterator of the (k+1)th smallest element
    tr.order_of_key(k);  // the number of elements are less than k
}
