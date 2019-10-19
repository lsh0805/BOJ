#include <stdio.h>

int N, M, K, dp[100001][31], curr[100001];

int main(){
    scanf("%d %d %d", &N, &K, &M);
    M -= 1;
    for(int i = 0; i < N; i++)
        scanf("%d", curr + i);
    for(int i = 1; i <= K; i++)
        scanf("%d", &dp[i][0]);
    for(int j = 1; j < 31; j++)
        for(int i = 1; i <= K; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    int m;
    for(int i = 0; i < N; i++){
        int time = M;
        for(int j = 30; j >= 0; j--){
            if(time >= 1 << j){
                time -= 1 << j;
                curr[i] = dp[curr[i]][j];
            }
        }
        printf("%d ", curr[i]);
    }

    return 0;
}