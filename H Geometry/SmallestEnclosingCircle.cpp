#include <bits/stdc++.h>

using namespace std;

#define eps 1e-12
#define db double

const int M = 100005;

bool equal(double a, double b) {
    return abs(a - b) < eps;
}

struct point {
    double x, y;
    point(db X = 0, db Y = 0) : x(X), y(Y) {}
    point operator+(db t) { return point(x + t, y + t); }
    point operator-(db t) { return point(x - t, y - t); }
    point operator*(db t) { return point(x * t, y * t); }
    point operator/(db t) { return point(x / t, y / t); }
    point operator+(point r) { return point(x + r.x, y + r.y); }
    point operator-(point r) { return point(x - r.x, y - r.y); }
    point rotate() { return point(y, -x); }
    db len() { return x * x + y * y; }
} p[M];

db cdt(point a, point b) {
    return a.x * b.x + a.y * b.y;
}
db crs(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
point get(point a, point l0, point b, point l1) {
    db k = crs(b - a, l1) / crs(l0, l1);
    return a + l0 * k;
}
point cir(point a, point b, point c) {
    return get((a + b) / 2, (b - a).rotate(), (b + c) / 2, (c - b).rotate());
}
pair<point, double> smallestEnclosingCircle(int n) {
    srand(time(0));
    random_shuffle(p + 1, p + 1 + n);
    point o;
    db r = 0;
    for (int i = 1; i <= n; i++) {
        if ((p[i] - o).len() > r) {
            o = p[i];
            r = 0;
            for (int j = 1; j < i; j++) {
                if ((o - p[j]).len() > r) {
                    o = (p[i] + p[j]) / 2;
                    r = (o - p[j]).len();
                    for (int k = 1; k < j; k++)
                        if ((o - p[k]).len() > r) {
                            o = cir(p[i], p[j], p[k]);
                            r = (o - p[k]).len();
                        }
                }
            }
        }
    }
    return make_pair(o, sqrt(r));
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    pair<point, double> ans = smallestEnclosingCircle(n);
    cout << fixed << setprecision(9) << ans.second << '\n';
    cout << fixed << setprecision(9) << ans.first.x << ' ';
    cout << fixed << setprecision(9) << ans.first.y << '\n';
    return 0;
}