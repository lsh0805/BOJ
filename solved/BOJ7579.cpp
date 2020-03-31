#include <bits/stdc++.h>

using namespace std;

int N, M, c[101], sum, ans;
long long a[101], dp[101][10001];

long long  process(int idx, int remain){
    long long  & ret = dp[idx][remain];
    if(remain - c[idx] < 0) return 0;
    if(ret != 0)
        return ret;
    ret = a[idx];
    for(int i = idx + 1; i < N; i++)
        ret = max(ret, process(i, remain - c[idx]) + a[idx]);
    return ret;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    for(int i = 0; i < N; i++){
        cin >> c[i];
        sum += c[i];
    }
    for(int j = 0; j <= sum; j++)
        for(int i = 0; i < N; i++)
            process(i, j);
    for(int j = 0; j <= sum; j++)
        for(int i = 0; i < N; i++)
            if(dp[i][j] >= M){
                cout << j;
                return 0;
            }
    return 0;
}