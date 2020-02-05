#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1001], arr[1001], N;
bool flag = false;
int solve(int curr){
    if(curr == N - 1){
        flag = true;
        return 0;
    }
    int & ret = dp[curr];
    if(ret != 0)
        return ret;
    ret = 1000000;
    for(int i = 1; i <= arr[curr]; i++){
        if(curr + i >= N) break;
        ret = min(ret, solve(curr + i) + 1);
    }
    return ret;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int ans = solve(0);
    if(flag)
        printf("%d", ans);
    else
    {
        printf("-1");
    }
    
    return 0;
}