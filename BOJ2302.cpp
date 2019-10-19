#include <stdio.h>

int N, M, before = 1, curr, ans = 1, dp[41];


int main(){
    scanf("%d %d", &N, &M);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    for(int i = 0; i < M; i++){
        scanf("%d", &curr);
        ans *= dp[curr - before];
        before = curr + 1;
    }
    curr = N + 1;
    ans *= dp[curr - before];
    printf("%d", ans);
    return 0;
}   