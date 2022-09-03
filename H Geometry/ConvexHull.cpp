#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define x first
#define y second

const int ON_LINE = 0;
const int LEFT = 1;
const int RIGHT = 2;

int point_location_test(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    // check the location of p3 is on the (LEFT/RIGHT/TOUCH) of the line
    if(p1 == p2){
        //no line found
    }
    pair<long long, long long> u = {p2.x - p1.x, p2.y - p1.y};
    pair<long long, long long> v = {p3.x - p1.x, p3.y - p1.y};
    long long cross_product = u.x * v.y - u.y * v.x;
    if(cross_product == 0){
        //cout<<"TOUCH\n";
        return ON_LINE;
    }else if(cross_product > 0){
        //cout<<"LEFT\n";
        return LEFT;
    }else{
        //cout<<"RIGHT\n";
        return RIGHT;
    }
}


vector<pair<int, int>> convex_hull(vector<pair<int, int>> points){
    sort(points.begin(), points.end());
    int n = points.size();
    vector<pair<int, int>> res;
    res.emplace_back(points[0]);
    res.emplace_back(points[1]);
    int index = 1;
    for(int i=2;i<n;i++){
        index = res.size();
        while(index > 1 && point_location_test(res[index-2], res[index-1], points[i]) == LEFT){
            res.pop_back();
            index--;
        }
        res.emplace_back(points[i]);
    }
    int g = res.size();
    g--;
    res.emplace_back(points[n-2]);
    for(int i=n-3;i>=0;i--){
        index = res.size();
        while(index - g > 1 && point_location_test(res[index-2], res[index-1], points[i]) == LEFT){
            res.pop_back();
            index--;
        }
        res.emplace_back(points[i]);
    }
    res.pop_back();
    cout<<res.size()<<'\n';
    for(int i=0;i<res.size();i++){
        cout<<res[i].x<<" "<<res[i].y<<'\n';
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> points;
    for(int i=0, x, y;i<n;i++){
        cin>>x>>y;
        points.emplace_back(x, y);
    }
    convex_hull(points);
    return 0;
}
