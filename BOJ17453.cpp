#include <stdio.h>

int dp[500001][19], M, Q, n, x;

int main(){
    scanf("%d", &M);
    for(int i = 1; i <= M; i++)
        scanf("%d", &dp[i][0]);
    scanf("%d", &Q);
    for(int j = 1; j < 19; j++)
        for(int i = 0; i <= M; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];  
    while(Q--){
        scanf("%d %d", &n, &x);
        for(int i = 19; i >= 0; i--){
            if(n >= (1 << i)){
                n -= 1 << i;
                x = dp[x][i];
            }
        }
        printf("%d\n", x);
    }
    return 0;
}