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

int N, A[51], B[51], A_B[51], B_A[51], v[51], a_cnt, b_cnt;
bool visited[51], prime[50001];

bool dfs(int a_idx) {
    visited[a_idx] = true;
    for (int b_idx = 0; b_idx < b_cnt; b_idx++) {
        if (!prime[A[a_idx] + B[b_idx]]) continue;
        if (B_A[b_idx] == -1 || !visited[B_A[b_idx]] && dfs(B_A[b_idx])) {
            A_B[a_idx] = b_idx;
            B_A[b_idx] = a_idx;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        if (v[0] % 2 == v[i] % 2) {
            A[a_cnt++] = v[i];
        } else {
            B[b_cnt++] = v[i];
        }
    }
    fill(prime + 2, prime + 50001, true);
    for (int i = 4; i <= 50000; i += 2)
        prime[i] = false;
    for (int i = 2; i * i <= 50000; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 50000; j += i * 2) {
            prime[j] = false;
        }
    }
    sort(B, B + b_cnt);
    bool flag = false;
    for (int b_idx = 0; b_idx < b_cnt; b_idx++) {
        if (!prime[A[0] + B[b_idx]]) continue;
        fill(A_B, A_B + N, -1);
        fill(B_A, B_A + N, -1);
        int match = 1;
        for (int a_idx = 1; a_idx < a_cnt; a_idx++) {
            if (A_B[a_idx] == -1) {
                fill(visited, visited + N, false);
                B_A[b_idx] = 0;
                visited[0] = true;
                if (dfs(a_idx)) match++;
            }
        }
        if (match == N / 2) {
            cout << B[b_idx] << ' ';
            flag = true;
        }
    }
    if (!flag) cout << "-1";
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