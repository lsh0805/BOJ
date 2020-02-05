#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1025][11], val[1025][11], T, N, M, ans;
bool m[11][11];
char c;

bool check(int x, int y, int prev){
    if(m[y][x] == false) return false;
    if(x > 0)
        if(prev & (1 << (x - 1)))
            return false;
    if(x < M - 1)
        if(prev & (1 << (x + 1)))
            return false;
    return true;
}
void process(int prev, int curr, int x, int y, int cnt){
    dp[curr][y] = max(dp[curr][y], dp[prev][y - 1] * (y != 0) + cnt);
    if(ans < dp[curr][y])
        ans = dp[curr][y];
    if(x >= M) return;
    if(check(x, y, prev))
        process(prev, curr | (1 << x), x + 2, y, cnt + 1);
    process(prev, curr, x + 1, y, cnt);
}


int main(){
    scanf("%d", &T);
    while(T--){
        ans = 0;
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++){
            getchar();
            for(int j = 0; j < M; j++)
                m[i][j] = (c = getchar()) == '.';
        }
        for(int i = 0; i < N; i++)
            for(int j = 0; j < (1 << M); j++)
                dp[j][i] = 0;
        process(0, 0, 0, 0, 0);
        for(int y = 1; y < N; y++){
            for(int prev = 0; prev < (1 << M); prev++){
                process(prev, 0, 0, y, 0);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}