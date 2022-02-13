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
typedef pair<int, int> ii;

int N, n[100001], x, ans;
bool a[1000001], visited[1000001];

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n[i];
        a[n[i]] = true;
    }
    cin >> x;
    for (int i = 0; i < N; i++) {
        int diff = x - n[i];
        if (diff <= 0 || visited[n[i]]) continue;
        visited[n[i]] = true;
        if (diff > 1000000 || !a[diff] || visited[diff]) {
            continue;
        }
        visited[diff] = true;
        ans++;
    }
    cout << ans;
    return 0;
}