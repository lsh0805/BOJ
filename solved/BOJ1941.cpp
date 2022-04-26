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

int N = 5, cnt, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, 1, -1};
bool state[5][5], visited[5][5];
vector<string> m(N);
int dfs(int y, int x) {
    visited[y][x] = true;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || !state[ny][nx] || visited[ny][nx]) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

bool f(const vector<int> &s) {
    int sy = -1, sx = -1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            state[i][j] = false;
            visited[i][j] = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!s[i]) continue;
        int y = i / 5, x = i % 5;
        state[y][x] = true;
        if (m[y][x] == 'S') cnt++;
        sy = y;
        sx = x;
    }
    if (cnt < 4 || dfs(sy, sx) < 7) return false;
    return true;
}

void solve() {
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }
    vector<int> p(18);
    for (int i = 0; i < 7; i++) {
        p.push_back(1);
    }
    int ans = 0;
    do {
        ans += f(p);
    } while (next_permutation(p.begin(), p.end()));
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