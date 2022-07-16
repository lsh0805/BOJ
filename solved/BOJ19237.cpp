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

int N, M, K, m[21][21], c[21][21], a[21][21], b[21][21], d[401], pr[401][4][4], dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
pair<int, int> pos[401];

void print_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int simulate() {
    for (int t = 0; t <= 1000; t++) {
        // print_map();
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (m[i][j] > 0) {
                    cnt++;
                }
            }
        }
        if (cnt == 1) return t;
        for (int i = 1; i <= M; i++) {
            int y = pos[i].fi;
            int x = pos[i].se;
            if (y == -1 && x == -1) continue;
            bool flag = false;
            for (int k = 0; k < 4; k++) {
                int dir = pr[i][d[i]][k];
                // dbg(i, k, dir);
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (m[ny][nx] == 0 && a[ny][nx] == 0) {
                    flag = true;
                    if (c[ny][nx] == 0) {
                        c[ny][nx] = i;
                        d[i] = dir;
                    } else {
                        pos[i] = {-1, -1};
                    }
                    break;
                }
            }
            if (flag) continue;
            for (int k = 0; k < 4; k++) {
                int dir = pr[i][d[i]][k];
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (a[ny][nx] == i) {
                    c[ny][nx] = i;
                    d[i] = dir;
                    break;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (b[i][j] > 0) {
                    if (--b[i][j] == 0) a[i][j] = 0;
                }
                if (c[i][j] > 0) {
                    // dbg(c[i][j], i, j);
                    a[i][j] = c[i][j];
                    b[i][j] = K;
                    pos[c[i][j]] = {i, j};
                }
                m[i][j] = c[i][j];
                c[i][j] = 0;
            }
        }
    }
    return -1;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
            if (m[i][j]) pos[m[i][j]] = {i, j};
            a[i][j] = m[i][j];
            b[i][j] = K;
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> d[i];
        d[i]--;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> pr[i][j][k];
                pr[i][j][k]--;
            }
        }
    }
    cout << simulate();
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