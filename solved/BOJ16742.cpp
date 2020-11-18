#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;

int N, M, ans, r[1001][1001];
P p[1001][1001];
char c[1001][1001];

P find(P u){
    if(p[u.fi][u.se] == u) return u;
    return p[u.fi][u.se] = find(p[u.fi][u.se]);
}

void merge(P u, P v){
    if(r[u.fi][u.se] < r[v.fi][v.se])
        swap(u, v);
    u = find(u);
    v = find(v);
    if(u == v) return;
    ans--;
    p[v.fi][v.se] = u;
    if(r[u.fi][u.se] == r[v.fi][v.se])
        r[u.fi][u.se]++;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    ans = N * M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> c[i][j];
             p[j][i] = P(j, i);
        }
    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++){
            int nx, ny;
            switch (c[y][x])
            {
            case 'U':
                nx = x, ny = y - 1;
                break;
            case 'D':
                nx = x, ny = y + 1;
                break;
            case 'L':
                nx = x - 1, ny = y;
                break;
            case 'R':
                nx = x + 1, ny = y;
                break;
            default:
                break;
            }
            merge(P(nx, ny), P(x, y));
        }
    cout << ans;
}