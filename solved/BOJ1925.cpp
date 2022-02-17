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

int N, M, max_, cnt, m[501][501], visited[501][501], sz,
dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

void dfs(int y, int x) {
    visited[y][x] = true;
    sz++;
    max_ = max(max_, sz);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || !m[ny][nx] || visited[ny][nx])
            continue;
        dfs(ny, nx);
    }
}

int main()
{
    IO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && m[i][j]) {
                cnt++;
                dfs(i, j);
                sz = 0;
            }
        }
    }
    cout << cnt << endl << max_;
    return 0;
}