#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;


int N, M, m[501][501];

P poly[19][4] = {
    {P(0, 0), P(0, 1), P(1, 0), P(1, 1)},

    {P(0, 0), P(0, 1), P(0, 2), P(0, 3)},
    {P(0, 0), P(1, 0), P(2, 0), P(3, 0)},

    {P(0, 0), P(1, 0), P(2, 0), P(2, 1)},
    {P(0, 0), P(0, 1), P(0, 2), P(1, 0)},
    {P(0, 0), P(0, 1), P(1, 1), P(2, 1)},
    {P(0, 2), P(1, 0), P(1, 1), P(1, 2)},

    {P(0, 1), P(1, 1), P(2, 0), P(2, 1)},
    {P(0, 0), P(1, 0), P(1, 1), P(1, 2)},
    {P(0, 0), P(0, 1), P(1, 0), P(2, 0)},
    {P(0, 0), P(0, 1), P(0, 2), P(1, 2)},

    {P(0, 0), P(1, 0), P(1, 1), P(2, 1)},
    {P(0, 1), P(0, 2), P(1, 0), P(1, 1)},
    {P(0, 1), P(1, 0), P(1, 1), P(2, 0)},
    {P(0, 0), P(0, 1), P(1, 1), P(1, 2)},

    {P(0, 0), P(0, 1), P(0, 2), P(1, 1)},
    {P(0, 1), P(1, 0), P(1, 1), P(2, 1)},
    {P(0, 1), P(1, 0), P(1, 1), P(1, 2)},
    {P(0, 0), P(1, 0), P(1, 1), P(2, 0)},
};

int solve(){
    int ret = 0;
    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            for(int i = 0; i < 19; i++){
                int sum = 0;
                for(int j = 0; j < 4; j++){
                    int n_y = y + poly[i][j].f, n_x = x + poly[i][j].s;
                    if(n_x >= M || n_y >= N) continue;
                    sum += m[n_y][n_x];
                }
                ret = max(sum, ret);
            }
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> m[i][j];
    cout << solve();    
}