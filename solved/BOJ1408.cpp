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

string a, b;

int sec(string str) {
    int h = (str[0] - '0') * 10 + str[1] - '0';
    int m = (str[3] - '0') * 10 + str[4] - '0';
    int s = (str[6] - '0') * 10 + str[7] - '0';
    return (h * 60 + m) * 60 + s;
}

string time(int sec) {
    string h = to_string(sec / 3600);
    sec %= 3600;
    string m = to_string(sec / 60);
    sec %= 60;
    string s = to_string(sec);
    return (h.length() < 2 ? "0" + h : h) + ":" + (m.length() < 2 ? "0" + m : m) + ":" + (s.length() < 2 ? "0" + s : s);
}

void solve() {
    cin >> a >> b;
    if (a < b)
        cout << time(sec(b) - sec(a));
    else
        cout << time(sec(b) + 3600 * 24 - sec(a));
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