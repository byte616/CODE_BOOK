#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define x first
#define y second

//Pick's theorem
// area = a + b/2 + 1
// a : 在 polygon 裡的點的數量
// b : 在 polygon 邊上的點的數量


int n;
pair<long long, long long> poly[1003];
long long find_2area(){
    //回傳多邊形的面積的兩倍
    //input 必須按照多邊形的順序
    //划船公式
    poly[n] = poly[0];
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum += poly[i].x * poly[i+1].y;
    }
    for(int i=1;i<=n;i++){
        sum -= poly[i].x * poly[i-1].y;
    }
    return sum > 0?sum:-sum;
}

long long find_boundary_node(){
    //算 polygon 的邊上有多少整數點
    long long sum = 0;
    for(int i=0, j, _x, _y, gd;i<n;i++){
        j = (i+1) % n;
        _x = abs(poly[j].x - poly[i].x);
        _y = abs(poly[j].y - poly[i].y);
        gd = __gcd(_x, _y);
        _x /= gd, _y /= gd;
        sum += gd;
    }
    //      a                     b
    //cout<<(area - bd)/2+1<<" "<<bd<<'\n';
    return sum;
}


