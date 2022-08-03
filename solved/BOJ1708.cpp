#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

typedef pair<int, int> pii;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;

int N;
typedef struct Point {
    ll x, y, p, q;
    Point() : Point(0, 0, 0, 0) {}
    Point(ll x_, ll y_) : Point(x_, y_, 0, 0) {}
    Point(ll x_, ll y_, ll p_, ll q_) : x(x_), y(y_), p(p_), q(q_) {}
    bool operator<(const Point &O) {
        if (q * O.p != p * O.q) return q * O.p < p * O.q;
        if (y != O.y) return y < O.y;
        return x < O.x;
    }
} Point;
Point points[100001];

ll ccw(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points, points + N);
    for (int i = 1; i < N; i++) {
        points[i].p = points[i].x - points[0].x;
        points[i].q = points[i].y - points[0].y;
    }
    sort(points + 1, points + N);
    stack<Point> st;
    st.push(points[0]);
    st.push(points[1]);
    int idx = 2;
    while (idx < N) {
        while (st.size() >= 2) {
            Point b = st.top();
            st.pop();
            Point a = st.top();
            if (ccw(a, b, points[idx]) > 0) {
                st.push(b);
                break;
            }
        }
        st.push(points[idx++]);
    }
    cout << st.size();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}