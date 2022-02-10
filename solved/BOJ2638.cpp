#include <bits/stdc++.h>
using namespace std;
#define IO                                                                     \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);                                                                \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define fi first
#define se second
typedef pair<int, int> ii;

int m[101][101], N, M, cheese_cnt, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
bool visited[101][101];

void dfs(int y, int x) {
    visited[y][x] = true; 
    m[y][x] = 2;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || m[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
}

int main() {
    IO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
            if (m[i][j] == 1) cheese_cnt++;
        }
    }
    int ans = 0;
    while (cheese_cnt) {
        dfs(0, 0);
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (m[i][j] == 1) {
                    int air = 0;
                    for (int k = 0; k < 4; k++) {
                        int ny = dy[k] + i, nx = dx[k] + j;
                        if (m[ny][nx] == 2) air++;
                        if (air >= 2) break;
                    }
                    if (air >= 2) {
                        m[i][j] = 3;
                        cheese_cnt--;
                    }
                }
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}