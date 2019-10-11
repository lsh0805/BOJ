#include <stdio.h>

int N, M, dp[15][15][1 << 14 + 1];
const int MOD = 9901;

int solve(int y, int x, int state){
    if(y == N) return state == 0;
    if(x > M) return 0;
    if(x == M) return solve(y + 1, 0, state);
    int & ret = dp[y][x][state];
    if(ret != -1)
        return ret;
    if((state & (1 << x)) == 0){
        ret = solve(y, x + 1, state | (1 << x)) % MOD;
        if((state & (1 << (x + 1))) == 0)
            ret += solve(y, x + 2, state) % MOD;
        return ret % MOD;
    }
    else
        return ret = solve(y, x + 1, state & (~(1 << x))) % MOD;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            for(int k = 0; k < (1 << 14) + 1; k++)
                dp[i][j][k] = -1;
    printf("%d", solve(0, 0, 0) % MOD);
    return 0;
}