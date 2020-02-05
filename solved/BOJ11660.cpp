#include <stdio.h>

int N, M, dp[1025][1025], arr[1025][1025], x1, y1, x2, y2;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = arr[i][j];
            if(i > 0)
                dp[i][j] += dp[i - 1][j];
            if(j > 0)
                dp[i][j] += dp[i][j - 1];
            if(i > 0 && j > 0)
                dp[i][j] -= dp[i - 1][j - 1];
        }
    }
    for(int i = 0; i < M; i++){
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        x1--, x2--, y1--, y2--;
        int ans = dp[y2][x2];
        if(y1 > 0)
            ans -= dp[y1 - 1][x2];
        if(x1 > 0)
            ans -= dp[y2][x1 - 1];
        if(y1 > 0 && x1 > 0)
            ans += dp[y1 - 1][x1 - 1];
        printf("%d\n", ans);
    }
    return 0;
}