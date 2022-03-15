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

int N, M, cnt[2], temp[2], dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
bool visited[251][251];
string m[251];

void dfs(int y, int x) {
    visited[y][x] = true;
    if (m[y][x] == 'o') temp[0]++;
    else if (m[y][x] == 'v') temp[1]++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
        if (m[ny][nx] == '#') continue;
        dfs(ny, nx);
    }
}

int main()
{
    IO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(!visited[i][j] && m[i][j] != '#') {
                dfs(i, j);
                if (temp[0] > temp[1]) {
                    cnt[0] += temp[0];
                } else {
                    cnt[1] += temp[1];
                }
                temp[0] = 0;
                temp[1] = 0;
            }
        }
    }
    cout << cnt[0] << " " << cnt[1];
    return 0;
}