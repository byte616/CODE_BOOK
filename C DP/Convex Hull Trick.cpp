#include<iostream>
#include<deque>
#include<cassert>
using namespace std;
using ll = long long;

struct Line{
        // y = ax + b
        ll a, b;
        Line(ll _a, ll _b):a(_a), b(_b){};
        ll value(ll x){
                return a * x + b;
        }
        void display()const{
                cout<<a<<" "<<b<<'\n';
        }
};

struct Convex_hull_trick{
        // 考慮一個直線集合 S，有 Q 筆操作
        // 每次操作可以放入直線(a, b)或者詢問某個 x 下 f(x) 在 S 中的最大值
        // 詢問多個 x 找目前放入的直線中最大的 ax + b
        // 輸入的 x 與 a 為單調遞增
        // O(Q)
        deque<Line> dq;
        bool kick_pre1(Line pre2, Line pre1, Line add){
                return (pre2.a - pre1.a) * (add.b - pre2.b) \
                        <= (pre2.a - add.a) * (pre1.b - pre2.b);
        }
        void insert(ll a, ll b){
                Line add(a, b);
                while(dq.size() > 1 && kick_pre1(dq[(int)dq.size()-2], dq.back(), add)){
                        dq.pop_back();
                }
                dq.emplace_back(add);
        };
        ll find_max(ll x){
                assert(dq.size() != 0);
                bool pop = true;
                while(dq.size() > 1 && pop){
                        pop = false;
                        ll l1 = dq[0].value(x);
                        ll l2 = dq[1].value(x);
                        if(l1 <= l2){
                                pop = false;
                                dq.pop_front();
                        }
                }
                return dq.front().value(x);
        }
        void display()const{
                for(const Line &l:dq){
                        l.display();
                }
        }
};

int main(){
        int q;
        cin>>q;
        ll mode, a, b, x;
        Convex_hull_trick cht;
        while(q--){
                cin>>mode;
                if(mode == 0){
                        cin>>a>>b;
                        cht.insert(a, b);
                }else{
                        cin>>x;
                        cout<<cht.find_max(x)<<'\n';
                }
                //cht.display();
        }
        return 0;
}
