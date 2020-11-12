#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
int R, C, m[21][21], dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0}, ans;
char c;

void dfs(int y, int x, int visit, int level){
    ans = max(ans, level);
    for(int i = 0; i < 4; i++){
        int n_y = y + dy[i];
        int n_x = x + dx[i];
        if(n_y < 0 || n_y >= R || n_x < 0 || n_x >= C) continue;
        if((visit & (1 << m[n_y][n_x])) == 0)
            dfs(n_y, n_x, visit | (1 << m[n_y][n_x]), level + 1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            cin >> c;
            m[i][j] = c - 'A';
        }
    dfs(0, 0, 1 << m[0][0], 1);
    cout << ans;
}