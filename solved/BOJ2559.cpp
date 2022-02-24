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

int N, K, a[100001], psum[100001], ans;

int main()
{
    IO;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        psum[i] = a[i];
        if (i != 0) {
            psum[i] += psum[i - 1];
        }
        if (i == K - 1) {
            ans = psum[i];
        } else if (i >= K) {
            ans = max(ans, psum[i] - psum[i - K]);
        }
    }
    cout << ans;
    return 0;
}