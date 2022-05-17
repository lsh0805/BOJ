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
const int MAX_M = 1e6 + 1;
int N, a[1001], last[MAX_M], cnt[MAX_M];
bool p[MAX_M];
vector<int> primes;

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    memset(p, true, sizeof(p));
    p[1] = false;
    for (int i = 4; i < MAX_M; i += 2)
        p[i] = false;
    for (int i = 3; i * i < MAX_M; i += 2) {
        if (!p[i]) continue;
        for (int j = i * i; j < MAX_M; j += i * 2) {
            p[j] = false;
        }
    }
    for (int i = 1; i < MAX_M; i++) {
        if (p[i])
            primes.push_back(i);
    }
    int ans = 0;
    for (int prime : primes) {
        for (int i = 0; i < N; i++) {
            int r = a[i] % prime;
            if (last[r] == prime) {
                cnt[r]++;
            } else {
                last[r] = prime;
                cnt[r] = 1;
            }
            ans = max(cnt[r], ans);
        }
    }
    if (a[N - 1] - a[0] >= MAX_M)
        ans = max(ans, 2);
    cout << ans;
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