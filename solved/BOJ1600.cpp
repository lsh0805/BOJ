#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, pair<int, int>> P;
queue<P> q;
int K, W, H, ans, m[201][201], visited[201][201][31], dy[12] = {-1, 1, 0, 0, -1, -2 ,-2 , -1, 1, 2, 2, 1}, dx[12] = {0, 0, -1, 1, -2, -1, 1, 2, 2, 1, -1, -2};

int main(){
    scanf("%d %d %d", &K, &W, &H);
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            scanf("%d", &m[i][j]);
    q.push(P(K, {0, 0}));
    visited[0][0][K] = true;
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){
            P curr = q.front();
            q.pop();
            int curr_k = curr.first;
            int curr_y = curr.second.first;
            int curr_x = curr.second.second;
            if(curr_x == W - 1 && curr_y == H - 1){
                printf("%d", ans);
                return 0;
            }
            for(int i = 0; i < 12; i++){
                if(i >= 4 && curr_k == 0) break;
                int next_y = curr_y + dy[i];
                int next_x = curr_x + dx[i];
                int next_k = curr_k - (i >= 4);
                if(next_x < 0 || next_x >= W || next_y < 0 || next_y >= H || visited[next_y][next_x][next_k] || m[next_y][next_x] == 1) continue;
                visited[next_y][next_x][next_k] = true;
                q.push(P(next_k, {next_y, next_x}));
            }
        }
        ans++;
    }
    printf("-1");
    return 0;
}