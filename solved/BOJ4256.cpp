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

int N, pre[1001], in[1001], l[1001], r[1001], root;

void construct(int pidx, int left, int right) {
    int p = pre[pidx];
    int idx = -1;
    for (int i = left; i <= right; i++) {
        if (in[i] == p) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        dbg(pidx, p);
        return;
    }
    if (left < idx) {
        l[p] = pre[pidx + 1];
        construct(pidx + 1, left, idx - 1);
    }
    if (idx < right) {
        r[p] = pre[pidx + idx - left + 1];
        construct(pidx + idx - left + 1, idx + 1, right);
    }
    dbg(left, right);
}

void postorder(int n) {
    if (l[n] != 0) postorder(l[n]);
    if (r[n] != 0) postorder(r[n]);
    cout << n << ' ';
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pre[i];
        l[i + 1] = 0;
        r[i + 1] = 0;
    }
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
    root = pre[0];
    construct(0, 0, N - 1);
    postorder(root);
    cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}