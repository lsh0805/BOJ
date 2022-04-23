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

int N, M, ids[1001][1001], cnt[1000001], id, m[1001][1001], dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
string str;
void dfs(int y, int x, int id) {
    ids[y][x] = id;
    cnt[id]++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || ids[ny][nx] != 0 || m[ny][nx] == 1) continue;
        dfs(ny, nx, id);
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            m[i][j] = str[j] - '0';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ids[i][j] == 0 && m[i][j] == 0) {
                id++;
                dfs(i, j, id);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (m[i][j] == 0) {
                cout << 0;
            } else {
                int sum = 1;
                vector<int> used;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k], nx = j + dx[k];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || m[ny][nx] == 1) continue;
                    bool flag = false;
                    for (int l = 0; l < used.size(); l++) {
                        if (used[l] == ids[ny][nx]) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) continue;
                    sum += cnt[ids[ny][nx]];
                    used.push_back(ids[ny][nx]);
                }
                cout << (sum % 10);
            }
        }
        cout << '\n';
    }
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