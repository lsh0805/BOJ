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

const int N = 10;
int ans, dy[5] = {-1, 0, 0, 0, 1}, dx[5] = {0, -1, 0, 1, 0};
char m[N][N];
bool on[N][N], original[N][N];

int simulate(int state) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0) {
                if ((1 << j) & state) {
                    res++;
                    for (int k = 0; k < 5; k++) {
                        int y = i + dy[k];
                        int x = j + dx[k];
                        if (y < 0 || y >= N || x < 0 || x >= N) continue;
                        on[y][x] = !on[y][x];
                    }
                }
            } else if (on[i - 1][j]) {
                res++;
                for (int k = 0; k < 5; k++) {
                    int y = i + dy[k];
                    int x = j + dx[k];
                    if (y < 0 || y >= N || x < 0 || x >= N) continue;
                    on[y][x] = !on[y][x];
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (on[i][j]) {
                return INF;
            }
        }
    }
    return res;
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
            on[i][j] = (m[i][j] == 'O');
            original[i][j] = on[i][j];
        }
    }
    ans = INF;
    for (int s = 0; s < (1 << 10); s++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                on[i][j] = original[i][j];
            }
        }
        int result = simulate(s);
        ans = min(ans, result);
    }

    cout << (ans == INF ? -1 : ans);
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