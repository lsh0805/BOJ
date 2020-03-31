#include <bits/stdc++.h>

int T, a, b, dp[101];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &a, &b);
        dp[0] = a % 10;
        for(int i = 1; i < 100; i++)
            dp[i] = (dp[i - 1] * dp[i - 1]) % 10;
        int ans = 1;
        for(int i = 0; b != 0; i++){
            if(b % 2){
                ans *= dp[i];
                ans %= 10;
            }
            b >>= 1;
        }
        if(ans == 0) ans = 10;
        printf("%d\n", ans);
    }
    return 0;
}