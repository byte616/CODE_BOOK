#include <bits/stdc++.h>
using namespace std;
#define DATA_BASE (0LL)  // 0 for Sum, 1e9 for Min, -1e9 for Max
// build: st.build(a);
// point update: st.point_update(x,y,new_val);
// rect query: st.rect_query(x1,y1,x2,y2);
// time: O(log(n)*log(m))
struct SegTree2D {
    using T = long long;

    int n, m;               // rows, cols (0-based external)
    vector<vector<T>> seg;  // seg[vx][vy] = inner tree value

    SegTree2D() : n(0), m(0) {}
    SegTree2D(int n, int m) { init(n, m); }

    void init(int n_, int m_) {
        n = n_;
        m = m_;
        seg.assign(4 * n, vector<T>(4 * m, (T)DATA_BASE));
    }

    static inline T pull(const T& a, const T& b) {
        return a + b;  // Sum
    }

    void build_y(int vx, int lx, int rx, int vy, int ly, int ry,
                 const vector<vector<T>>& a) {
        if (ly == ry) {
            if (lx == rx) {
                seg[vx][vy] = a[lx][ly];
            } else {
                seg[vx][vy] = pull(seg[vx * 2][vy], seg[vx * 2 + 1][vy]);
            }
        } else {
            int my = (ly + ry) >> 1;
            build_y(vx, lx, rx, vy * 2, ly, my, a);
            build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, a);
            seg[vx][vy] = pull(seg[vx][vy * 2], seg[vx][vy * 2 + 1]);
        }
    }

    void build_x(int vx, int lx, int rx, const vector<vector<T>>& a) {
        if (lx != rx) {
            int mx = (lx + rx) >> 1;
            build_x(vx * 2, lx, mx, a);
            build_x(vx * 2 + 1, mx + 1, rx, a);
        }
        build_y(vx, lx, rx, 1, 0, m - 1, a);
    }

    void build(const vector<vector<T>>& a) {
        init((int)a.size(), (int)(a.empty() ? 0 : a[0].size()));
        if (n == 0 || m == 0) return;
        build_x(1, 0, n - 1, a);
    }

    void update_y(int vx, int lx, int rx, int vy, int ly, int ry,
                  int x, int y, T new_val) {
        if (ly == ry) {
            if (lx == rx) {
                seg[vx][vy] = new_val;
            } else {
                seg[vx][vy] = pull(seg[vx * 2][vy], seg[vx * 2 + 1][vy]);
            }
        } else {
            int my = (ly + ry) >> 1;
            if (y <= my)
                update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
            else
                update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
            seg[vx][vy] = pull(seg[vx][vy * 2], seg[vx][vy * 2 + 1]);
        }
    }

    void update_x(int vx, int lx, int rx, int x, int y, T new_val) {
        if (lx != rx) {
            int mx = (lx + rx) >> 1;
            if (x <= mx)
                update_x(vx * 2, lx, mx, x, y, new_val);
            else
                update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
        }
        update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
    }

    void point_update(int x, int y, T new_val) {
        update_x(1, 0, n - 1, x, y, new_val);
    }

    T query_y(int vx, int vy, int tly, int try_, int ly, int ry) const {
        if (ly > ry) return (T)DATA_BASE;
        if (ly == tly && ry == try_) return seg[vx][vy];
        int tmy = (tly + try_) >> 1;
        T left = query_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy));
        T right = query_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
        return pull(left, right);
    }

    T query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) const {
        if (lx > rx) return (T)DATA_BASE;
        if (lx == tlx && rx == trx)
            return query_y(vx, 1, 0, m - 1, ly, ry);
        int tmx = (tlx + trx) >> 1;
        T left = query_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry);
        T right = query_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
        return pull(left, right);
    }

    // st.rect_query(1,1,3,3)
    T rect_query(int x1, int y1, int x2, int y2) const {
        return query_x(1, 0, n - 1, x1, x2, y1, y2);
    }
};
