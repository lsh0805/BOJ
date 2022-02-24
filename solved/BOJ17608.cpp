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

int N, a[100001], ans, max_;

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        if (max_ < a[i]) {
            max_ = a[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}