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

int N, M, dy[4] = { -1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}, ans, level;
char m[1001][1001];
queue<pii> f_q, j_q;
bool visited[1001][1001];

void spread() {
    int qsize = f_q.size();
    for (int i = 0; i < qsize; i++) {
        auto curr = f_q.front();
        f_q.pop();
        for (int j = 0; j < 4; j++) {
            int n_x = curr.se + dx[j];
            int n_y = curr.fi + dy[j];
            if (n_x < 0 || n_x >= M || n_y < 0 || n_y >= N) continue;
            if (m[n_y][n_x] == '#' || m[n_y][n_x] == 'F') continue;
            f_q.push({n_y, n_x});
            m[n_y][n_x] = 'F';
        }
    }
}

// void print_map() {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             cout << m[i][j];
//         }
//         cout << "\n";
//     }
//         cout << "\n";

// }

int main()
{
    IO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
            if (m[i][j] == 'F')
                f_q.push({i, j});
            else if(m[i][j] == 'J') {
                j_q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    while(!j_q.empty()) {
        spread();
        int qsize = j_q.size();
        for (int i = 0; i < qsize; i++) {
            auto curr = j_q.front();
            j_q.pop();
            if (curr.fi == N - 1 || curr.fi == 0 || curr.se == M - 1 || curr.se == 0) {
                ans = level + 1;
                break;
            }
            for (int j = 0; j < 4; j++) {
                int n_x = curr.se + dx[j];
                int n_y = curr.fi + dy[j];
                if (n_x < 0 || n_x >= M || n_y < 0 || n_y >= N) continue;
                if (m[n_y][n_x] == '#' || m[n_y][n_x] == 'F' || visited[n_y][n_x]) continue;
                visited[n_y][n_x] = true;
                j_q.push({n_y, n_x});
            }
        }
        if (ans != 0) break;
        // print_map();
        level++;
    }
    if (ans == 0) {
        cout << "IMPOSSIBLE";
    } else {
        cout << ans;
    }
    return 0;
}