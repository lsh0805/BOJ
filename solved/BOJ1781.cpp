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

int N, ans, d[200001], p[200001], seg[200001 * 4];
vector<pair<int, int>> v;

int init(int nl, int nr, int n) {
    if (nl > N || nr <= 0) return seg[n] = -1;
    if (nl == nr) return seg[n] = nl;
    int mid = (nl + nr) / 2;
    return seg[n] = max(init(nl, mid, 2 * n), init(mid + 1, nr, 2 * n + 1));
}

int update(int idx, int nl, int nr, int n, int val) {
    if (idx < nl || nr < idx) return seg[n];
    if (idx == nl && idx == nr) return seg[n] = val;
    int mid = (nl + nr) / 2;
    return seg[n] = max(update(idx, nl, mid, 2 * n, val), update(idx, mid + 1, nr, 2 * n + 1, val));
}
int query(int l, int r, int nl, int nr, int n) {
    if (nr < l || nl > r) {
        return -1;
    }
    if (nl >= l && r >= nr) return seg[n];
    int mid = (nl + nr) / 2;
    return max(query(l, r, nl, mid, 2 * n), query(l, r, mid + 1, nr, 2 * n + 1));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d[i] >> p[i];
        v.push_back({-p[i], d[i]});
    }
    sort(v.begin(), v.end());
    init(1, N, 1);
    for (int i = 0; i < N; i++) {
        int idx = query(1, v[i].second, 1, N, 1);
        if (idx == -1) continue;
        update(idx, 1, N, 1, -1);
        ans += -v[i].first;
    }
    cout << ans;
}
