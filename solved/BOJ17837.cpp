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

int N, K, m[13][13], dy[4] = {0, 0, -1, 1}, dx[4] = {1, -1, 0, 0};
vector<int> w[13][13];
vector<ar<int, 3>> v;

void solve() {
    cin >> N >> K;
    v = vector<ar<int, 3>>(K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][0]--;
        v[i][1]--;
        v[i][2]--;
        w[v[i][0]][v[i][1]].push_back(i);
    }
    int ans = 0;
    while (ans < 1000) {
        ans++;
        for (int i = 0; i < K; i++) {
            int y = v[i][0], x = v[i][1];
            int ny = y + dy[v[i][2]], nx = x + dx[v[i][2]];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N || m[ny][nx] == 2) {
                v[i][2] = (v[i][2] % 2 ? v[i][2] - 1 : v[i][2] + 1);
                ny = y + dy[v[i][2]], nx = x + dx[v[i][2]];
            }
            if (ny < 0 || ny >= N || nx < 0 || nx >= N || m[ny][nx] == 2) continue;
            int idx = -1;
            for (int j = 0; j < w[y][x].size(); j++) {
                if (w[y][x][j] == i) idx = j;
            }
            if (idx == -1) dbg("error");

            if (m[ny][nx] == 0) {
                reverse(w[y][x].begin() + idx, w[y][x].end());
            }
            int sz = w[y][x].size();
            for (int j = sz - 1; j >= idx; j--) {
                int back = w[y][x].back();
                w[y][x].pop_back();
                w[ny][nx].push_back(back);
                v[back][0] = ny, v[back][1] = nx;
            }

            if (w[ny][nx].size() >= 4) {
                cout << ans;
                return;
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