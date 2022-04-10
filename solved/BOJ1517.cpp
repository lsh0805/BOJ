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

int N, a[500001], b[500001];

ll merge(int s1, int e1, int s2, int e2) {
    ll ret = 0;
    int s = s1, e = e2;
    queue<int> q;
    while (s1 <= e1 || s2 <= e2) {
        if (s1 > e1) {
            q.push(b[s2++]);
        } else if (s2 > e2) {
            q.push(b[s1++]);
        } else if (b[s1] > b[s2]) {
            ret += e1 - s1 + 1;
            q.push(b[s2++]);
        } else {
            q.push(b[s1++]);
        }
    }
    for (int i = s; i <= e; i++) {
        int front = q.front();
        q.pop();
        b[i] = front;
    }
    return ret;
}

ll mergesort(int l, int r) {
    if (l == r) {
        b[l] = a[l];
        return 0;
    }
    ll ret = 0;
    int mid = (l + r) / 2;
    ret += mergesort(l, mid);
    ret += mergesort(mid + 1, r);
    ret += merge(l, mid, mid + 1, r);
    return ret;
}

int bubblesort() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ret++;
            }
        }
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    cout << mergesort(0, N - 1) << '\n';
    dbg(bubblesort());
}

int main() {
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