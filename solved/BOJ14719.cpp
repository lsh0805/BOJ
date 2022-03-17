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

int H, W, h[501], ans;
vector<pii> v;

int main()
{
    IO;
    cin >> H >> W;
    int prev;
    for(int i = 0; i < W; i++) {
        cin >> h[i];
        while(!v.empty() && v.back().fi < h[i]) {
            prev = v.back().fi;
            v.pop_back();
            if (v.empty()) break;
            int dist = i - v.back().se - 1;
            int height = min(h[i], v.back().fi) - prev;
            ans += dist * height;
        }
        v.push_back({h[i], i});
    }
    cout << ans;
    return 0;
}