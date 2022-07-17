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

int point[] = {
    0, 2, 4, 6, 8,
    10, 12, 14, 16, 18,
    20, 22, 24, 26, 28,
    30, 32, 34, 36, 38,
    40, 13, 16, 19, 25,
    26, 27, 28, 22, 24,
    30, 35, 0};
int n[10], pos[4];
const int T = 10, S = 0, E = 32;
vector<vector<int>> adj = {
    {1}, {2}, {3}, {4}, {5}, {6, 21}, {7}, {8}, {9}, {10}, {11, 28}, {12}, {13}, {14}, {15}, {16, 27}, {17}, {18}, {19}, {20}, {32}, {22}, {23}, {24}, {30}, {24}, {25}, {26}, {29}, {24}, {31}, {20}};

int simulate(int turn) {
    if (turn == T) return 0;
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if (pos[i] == E) continue;
        int cnt = n[turn];
        int o = pos[i];
        if (pos[i] == 5 || pos[i] == 10 || pos[i] == 15) {
            pos[i] = adj[pos[i]][1];
            cnt--;
        }
        for (int j = 0; j < cnt; j++) {
            if (pos[i] == E) break;
            pos[i] = adj[pos[i]][0];
        }
        bool flag = false;
        if (pos[i] != E) {
            for (int j = 0; j < 4; j++) {
                if (i == j) continue;
                if (pos[i] == pos[j]) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            pos[i] = o;
            continue;
        }
        ret = max(ret, simulate(turn + 1) + point[pos[i]]);
        pos[i] = o;
    }
    return ret;
}

void solve() {
    for (int i = 0; i < 10; i++) {
        cin >> n[i];
    }
    cout << simulate(0);
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