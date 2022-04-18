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

typedef pair<pair<int, int>, int> pii;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;

int N, M, K, m[1001][1001], visited[1001][1001], ans, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
string s;
void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            m[i][j] = s[j] - '0';
            visited[i][j] = K + 1;
        }
    }
    queue<pii> q;
    q.push({{0, 0}, 0});
    visited[0][0] = 0;
    while (!q.empty()) {
        int qsize = q.size();
        ans++;
        for (int i = 0; i < qsize; i++) {
            auto front = q.front();
            int y = front.fi.fi, x = front.fi.se, k = front.se;
            q.pop();
            if (y == N - 1 && x == M - 1) {
                cout << ans;
                // dbg(k);
                return;
            }
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j], ny = y + dy[j], nk = k + m[ny][nx];
                if (nx < 0 || nx >= M || ny < 0 || ny >= N || nk > K || visited[ny][nx] <= nk) continue;
                q.push({{ny, nx}, nk});
                visited[ny][nx] = nk;
            }
        }
    }
    cout << -1;
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