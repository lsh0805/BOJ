#include <stdio.h>
#include <memory.h>

int T, N, M, dp[21][10001], arr[21];

int solve(int n, int remain){
    if(remain <= 0) return remain == 0;
    if(n == N) return 0;
    int & ret = dp[n][remain];
    if(ret != - 1)
        return ret;
    return ret = solve(n, remain - arr[n]) + solve(n + 1, remain);
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < N; i++)
            scanf("%d", arr + i);
        scanf("%d", &M);
        printf("%d\n", solve(0, M));
    }
    return 0;
}