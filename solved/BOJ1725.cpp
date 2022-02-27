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

int N, h[100001];

int solve(int st, int ed) {
    if (st > ed) return 0;
    if (st == ed) return h[st];
    int mid = (st + ed) / 2;
    int ret = max(solve(st, mid), solve(mid + 1, ed));
    int l = mid, r = mid, height = h[mid], width = 1;
    ret = max(ret, width * height);
    while(l > st || r < ed) {
        if (l > st && r < ed) {
            if (h[l - 1] > h[r + 1])
                height = min(height, h[--l]);
            else
                height = min(height, h[++r]);
        } else if (l > st) {
            height = min(height, h[--l]);
        } else if (r < ed) {
            height = min(height, h[++r]);
        }
        width++;
        ret = max(ret, width * height);
    }
    return ret;
}

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    cout << solve(0, N - 1);
    return 0;
}