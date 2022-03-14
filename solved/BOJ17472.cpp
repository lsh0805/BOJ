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

int N, M, m[10][10], id, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1},
ids[10][10], d[7][7];
bool visited[10][10];

void numbering(int y, int x) {
    ids[y][x] = id;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || ids[ny][nx]) continue;
        if (!m[ny][nx]) continue;
        numbering(ny, nx);
    }
}

void finding(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y, nx = x;
        for (int dist = 0; true; dist++) {
            ny += dy[i];
            nx += dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
            if (m[ny][nx] == 0) continue;
            if (ids[ny][nx] == ids[y][x]) break;
            if (dist == 1) break;
            d[ids[ny][nx]][ids[y][x]] = min(d[ids[ny][nx]][ids[y][x]], dist);
            d[ids[y][x]][ids[ny][nx]] = min(d[ids[y][x]][ids[ny][nx]], dist);
            break;
        }
    }
}

void dfs(int y, int x) {
    visited[y][x] = true;
    finding(y, x);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
        if (ids[ny][nx] != ids[y][x]) continue;
        dfs(ny, nx);
    }
}

void print_array() {
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ids[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int getMin(int connected) {
    if (connected == (1 << id) - 1)
        return 0;
    int ret = 2e9;
    for (int start = 1; start <= id; start++) {
        if (connected & (1 << (start - 1))) {
            for (int next = 1; next <= id; next++) {
                if ((connected & (1 << (next - 1))) || d[start][next] == 2e9) continue;
                ret = min(ret, getMin(connected | (1 << (next - 1))) + d[start][next]);
            }
        }
    }
    return ret;
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
            if (m[i][j] && !ids[i][j]) {
                ++id;
                numbering(i, j);
            }
        }
    }
    for (int i = 1; i <= id; i++) {
        for (int j = 1; j <= id; j++) {
            d[i][j] = 2e9;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (m[i][j] && !visited[i][j]) {
                dfs(i, j);
            }
        }
    }
    // print_array();
    int ans = getMin(1);
    if (ans >= 2e9) {
        cout << "-1";
    } else {
        cout << ans;
    }
    return 0;
}