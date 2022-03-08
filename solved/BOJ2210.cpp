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

int ans, m[5][5], dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
bool visited[1000000];

void search(int y, int x, int curr, int cnt) {
    if (cnt == 6) {
        if (!visited[curr]) {
            visited[curr] = true;
            ans++;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
        search(ny, nx, curr * 10 + m[ny][nx], cnt+1);
    }
}

int main()
{
    IO;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> m[i][j];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            search(i, j, m[i][j], 1);
    cout << ans;
    return 0;
}