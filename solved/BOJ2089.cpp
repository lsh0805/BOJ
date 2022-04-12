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

int N;
bool ans[100];
void solve() {
    // cin >> N;
    // ll idx = N < 0, sum = 0;
    // if (N >= 0) {
    //     while (true) {
    //         ans[idx] = true;
    //         sum += (1LL << idx);
    //         if (sum >= N) break;
    //         idx += 2;
    //     }
    //     ll r = sum - N;
    //     for (ll i = idx; i >= 0; i--) {
    //         ll curr = (1LL << i) * (i % 2 == 0 ? 1 : -1);
    //         if (i % 2) {
    //             if (r + curr >= 0) {
    //                 r += curr;
    //                 ans[i] = true;
    //             }
    //         } else {
    //             if (r - curr >= 0) {
    //                 r -= curr;
    //                 ans[i] = false;
    //             }
    //         }
    //     }
    // } else {
    //     while (true) {
    //         ans[idx] = true;
    //         sum += (1 << idx) * -1;
    //         if (sum <= N) break;
    //         idx += 2;
    //     }
    //     ll r = sum - N;
    //     for (ll i = idx; i >= 0; i--) {
    //         ll curr = (1LL << i) * (i % 2 == 0 ? 1 : -1);
    //         if (i % 2) {
    //             if (r - curr <= 0) {
    //                 r -= curr;
    //                 ans[i] = false;
    //             }
    //         } else {
    //             if (r + curr <= 0) {
    //                 r += curr;
    //                 ans[i] = true;
    //             }
    //         }
    //     }
    // }
    // dbg(idx);
    // while (idx > 0 && ans[idx] == false) {
    //     idx--;
    // }
    // dbg(idx);
    // sum = 0;
    // for (int i = idx; i >= 0; i--) {
    //     cout << ans[i];
    //     if (ans[i])
    //         sum += (1LL << i) * (i % 2 == 0 ? 1 : -1);
    // }
    // dbg(sum);
    cin >> N;
    int idx = 0;
    while (N != 0) {
        if (N % 2) {
            ans[idx] = true;
            N--;
        }
        N /= -2;
        idx++;
    }
    while (idx > 0 && ans[idx] == false) {
        idx--;
    }
    for (; idx >= 0; idx--) {
        cout << ans[idx];
    }
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