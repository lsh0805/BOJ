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

typedef ar<ar<pii, 4>, 4> status;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;

int N = 4, dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}, a, b, ans;
status m;
set<status> visited;

int brute(status curr) {
    visited.insert(curr);
    int ret = 0;
    pii cords[17];
    fill(cords, cords + 17, make_pair(-1, -1));
    int dirs[17];
    fill(dirs, dirs + 17, -1);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (curr[i][j].fi == -1) continue;
            sum += curr[i][j].fi;
            cords[curr[i][j].fi] = {i, j};
            dirs[curr[i][j].fi] = curr[i][j].se;
        }
    }
    for (int i = 1; i <= N * N; i++) {
        int x = cords[i].se, y = cords[i].fi;
        if (x == -1) continue;
        while (true) {
            int nx = x + dx[dirs[i]], ny = y + dy[dirs[i]];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || curr[ny][nx].fi == 0) {
                dirs[i] = (dirs[i] + 1) % 8;
                curr[y][x].se = dirs[i];
            } else {
                if (curr[ny][nx].fi != -1)
                    swap(cords[curr[ny][nx].fi], cords[i]);
                else
                    cords[i] = {ny, nx};
                swap(curr[ny][nx], curr[y][x]);
                break;
            }
        }
    }
    for (int i = 1; true; i++) {
        int x = cords[0].se, y = cords[0].fi;
        int nx = x + dx[dirs[0]] * i, ny = y + dy[dirs[0]] * i;
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
        if (curr[ny][nx].fi != -1) {
            status next = curr;
            next[y][x] = {-1, -1};
            next[ny][nx] = {0, curr[ny][nx].se};
            if (visited.find(next) != visited.end()) continue;
            ret = max(ret, brute(next) + curr[ny][nx].fi);
        }
    }
    return ret;
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j].fi >> m[i][j].se;
            --m[i][j].se;
        }
    }
    ans = m[0][0].fi;
    m[0][0].fi = 0;
    ans += brute(m);
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