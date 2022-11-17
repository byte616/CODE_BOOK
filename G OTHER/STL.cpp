#include<algorithm>// fill, sort, __gcd
#include <cstring> // memset

//fill
vector<int> v(5);
fill(v.begin(), v.end(), -1);
fill(a, a+n, 0);

//memset
void* memset( void* dest, int ch, std::size_t count );
int a[20];
std::memset(a, 0, sizeof a);

// sort

bool cmp(int a, int b){
    // should not put '=' in return, '=' will causing RE
    if(a %2 != b % 2){
        return a % 2 > b % 2;
    }
    return a > b;
}
sort(a, a+n, cmp);
lower_bound(a, a+n, x);// first element y >= x
upper_bound(a, a+n, x);// first element y > x


#include<map> // header file of map
#include<set> // header file of set

// 宣告
map<int, int> mp;
set<int> s;
//自訂型態: key要有operator <

// usage

// add thing in it
    mp[x] = y;
    s.insert(x);
// access thing
    y = mp[x];
// check x exist or not
    mp.find(x) != mp.end();
    s.find(x) != s.end();
// check empty
    mp.empty();
    s.empty();
// check size
    mp.size();
    s.size();
// binary search
    map<int, int>::iterator it = mp.lower_bound(x);
    set<int>::iterator it2 = s.lower_bound(x);
    if(it == mp.end()){}//not found
    *it;// the first element y >= x
    // upper_bound: first element y > x
      
      
#include<queue> // header file of queue and priority_queue
#include<stack> // herder file of stack


// 宣告
queue<int> q;

priority_queue<int> pq;// max heap
priority_queue<int, vector<int>, greater<int>> pq;// min heap
//priority_queue 自訂排序法要寫 operator < and don't forget to add const
struct Point{
    int a, b;
    bool operator < (const Point& right)const{
        if(a != right.a)    return a < right.a;
        return b < b.right.b;
    }
}
priority_queue<Point> pq;

stack<int> st;

// usage

// add thing in it
    q.push(x);
    pq.push(x);
    st.push(x);
// access thing
    x = q.front();
    x = pq.top();
    x = st.top();
// take the thing out of it
    q.pop();
    pq.pop();
    st.pop();
// check empty
    q.empty();
// check size
    q.size();


#include<sstream>// header file of stringstream

stringstream ss;

void init(){// initialize stringstream
    ss.str("");
    ss.clear();
}

void usage(){
    // just use it like cin, cout
    ss<<t;// put t into ss
    ss>>t;// put a token of value to t
}
