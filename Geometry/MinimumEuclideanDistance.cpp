#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

int n;
struct Point{
    long long x, y;
    Point(){};
    Point(long long _x, long long _y):x(_x), y(_y){};
    
    bool operator!=(const Point& r)const{
        return x != r.x || y != r.y;
    }
    bool operator<(const Point& r)const{
        if(x != r.x)    return x < r.x;
        return y < r.y;
    }
    bool operator>(const Point& r)const{
        if(x != r.x)    return x > r.x;
        return y > r.y;
    }
    long long distance(const Point &r)const{
        return (r.x-x) * (r.x-x) + (r.y-y) * (r.y-y);
    }
};


vector<Point> a;


long long find_min_distance(){
    sort(a.begin(), a.end());
    int left=0;
    long long ans = a[0].distance(a[1]);
    set<Point> st;
    for(int right = 0;right<n;right++){
        //算的是距離的平方，剔除人的時候要開根號去看
        long long d = ceil(sqrt(ans));
        while(left < right && a[left].x < a[right].x - d){
            //確定裡面的 x 都是候選人，set 裡的以 y 為重
            st.erase(Point(a[left].y, a[left].x));
            left++;
        }
        //對 y 二分搜，找 (y-d, y+d) 區間的點
        auto down = st.lower_bound(Point(a[right].y - d, a[right].x - d));
        auto up = st.upper_bound(Point(a[right].y + d, a[right].x));
        for(auto it = down;it != up;it++){
            ans = min(ans, a[right].distance(Point(it->y, it->x)));
        }
        st.insert(Point(a[right].y, a[right].x));
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    long long f, g;
    for(int i=0;i<n;i++){
        cin>>f>>g;
        a.emplace_back(f, g);
    }
    cout<<find_min_distance()<<'\n';
    return 0;
}
