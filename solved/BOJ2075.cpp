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
typedef pair<int, pair<int, int>> pii;

int N, a[1501][1501], ans;
priority_queue<pii> pq;

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            if (i == N - 1)
                pq.push({a[N - 1][j], {i, j}});
        }
    }
    while(N--) {
        pii top = pq.top();
        ans = top.fi;
        int i = top.se.fi;
        int j = top.se.se;
        pq.pop();
        pq.push({a[i - 1][j], {i - 1, j}});
    }
    cout << ans;
    return 0;
}