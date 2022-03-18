#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define fi first
#define se second
typedef pair<int, int> pii;

int N, a[100001], ans, len, p;
vector<pii> v;
bool desc = true;

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if(!v.empty() && v.back().fi == a[i]) {
            v.back().se++;
        } else {
            v.push_back({a[i], 1});
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (desc) {
            if(p <= v[i].fi) {
                len += v[i].se;
            } else {
                desc = !desc;
                len = v[i - 1].se + v[i].se;
            }
        } else {
            if(p >= v[i].fi) {
                len += v[i].se;
            } else {
                desc = !desc;
                len = v[i - 1].se + v[i].se;
            }
        }
        ans = max(ans, len);
        p = v[i].fi;
    }
    cout << ans;
    return 0;
}