#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
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

int N, K;
string str;
vector<int> a;
priority_queue<pii> pq;
queue<int> q;

void solve() {
    cin >> N >> K >> str;
    a = vector<int>(N, 0);
    for (int i = 0; i < str.length(); i++)
        a[i] = str[i] - '0';

    int curr = 0, st = 0;
    while(K > 0 && curr < N) {
        int ed = min(N - 1, st + K);
        for (; curr <= ed; curr++) {
            pq.push({a[curr], -curr});
        }
        while(-pq.top().se < st) {
            pq.pop();
        }
        cout << pq.top().fi;
        K -= -pq.top().se - st;
        st = -pq.top().se + 1;
        dbg(curr, K, st, ed);
    }
    for (; curr < N; curr++) {
        cout << a[curr];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}