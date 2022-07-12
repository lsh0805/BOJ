#include <iostream>
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

int N, H, m[51][51], dp[51][51], dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, 1, -1};
bool visited[51][51], finished[51][51];

int f(int x, int y) {
    if (visited[y][x] && !finished[y][x]) {
        return 100000;
    }
    visited[y][x] = true;
    int &ret = dp[y][x];
    if (ret != -1) {
        finished[y][x] = true;
        return dp[y][x];
    }
    ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y;
        int nx = x;
        int cnt = 0;
        bool flag = false;
        while (ny < N && nx < H && nx >= 0 && ny >= 0) {
            if (cnt == m[y][x]) {
                flag = m[ny][nx] != 0 ? true : false;
                break;
            }
            ny += dy[i];
            nx += dx[i];
            cnt++;
        }
        if (flag) ret = max(ret, f(nx, ny) + 1);
    }
    ret = max(ret, 1);
    finished[y][x] = true;
    return ret;
}

void solve() {
    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < H; j++) {
            char c;
            cin >> c;
            if (c == 'H')
                m[i][j] = 0;
            else
                m[i][j] = c - '0';
            dp[i][j] = -1;
        }
    }
    int ans = f(0, 0);
    if (ans >= 100000) ans = -1;
    cout << ans << '\n';
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