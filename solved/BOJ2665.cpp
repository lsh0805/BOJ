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

int N, m[51][51], dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}, visited[51][51];
bool inserted[51][51];
string str;
queue<pii> cq, nq;

void dfs(int y, int x, int cnt) {
    visited[y][x] = cnt;
    if (y == N - 1 && x == N - 1) return;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] >= 0) continue;
        if (m[ny][nx] == 0) {
            if (!inserted[ny][nx]) {
                nq.push({ny, nx});
                inserted[ny][nx] = true;
            }
            continue;
        }
        dfs(ny, nx, cnt);
    }
}

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            m[i][j] = str[j] - '0';
            visited[i][j] = -1;
        }
    }
    cq.push({0, 0});
    inserted[0][0] = true;
    for (int cnt = 0; cnt < N * N; cnt++) {
        while(!cq.empty()) {
            auto top = cq.front();
            cq.pop();
            int y = top.fi, x = top.se;
            if(visited[y][x] == -1) {
                dfs(y, x, cnt);
            }
        }
        if (visited[N - 1][N - 1] >= 0) break;
        if (nq.empty()) break;
        std::swap(cq, nq);
    }
    cout << visited[N - 1][N - 1];
    return 0;
}