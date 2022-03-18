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

int N, M, cost[101], t[101], a, b;

void solve(int curr) {
    if (t[curr] != 0) {
        if (cost[t[curr]] > cost[curr]) {
            cost[t[curr]] = cost[curr];
            solve(t[curr]);
        }
        return;
    }
    for (int next = curr + 1; next <= curr + 6 && next <= 100; next++) {
        if (cost[next] > cost[curr] + 1) {
            cost[next] = cost[curr] + 1;
            solve(next);
        }
    }
}

int main()
{
    IO;
    cin >> N >> M;
    for (int i = 2; i <= 100; i++)
        cost[i] = 100;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        t[a] = b;
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        t[a] = b;
    }
    solve(1);
    cout << cost[100];
    return 0;
}