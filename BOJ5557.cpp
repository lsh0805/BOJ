#include <stdio.h>

long long dp[21][101];
int  N, M, arr[101];

long long solve(int num, int idx){
    if(num < 0 || num > 20)
        return 0;
    if(idx == N - 2)
        return num == M;
    long long & ret = dp[num][idx];
    if(ret != -1)
        return ret;
    return ret = solve(num + arr[idx + 1], idx + 1) + solve(num - arr[idx + 1], idx + 1);
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < 21; i ++)
        for(int j = 0; j < 101; j++)
            dp[i][j] = -1;
    for(int i = 0; i < N - 1; i++){
        scanf("%d", arr + i);
    }
    scanf("%d", &M);
    printf("%lld", solve(arr[0], 0));
    return 0;
}