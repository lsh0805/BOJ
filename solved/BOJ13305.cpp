#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100001;
int N, c[MAX_N], d[MAX_N], min_ = 2e9;
long long ans;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++)
        scanf("%d", d + i);
    for(int i = 0; i < N; i++)
        scanf("%d", c + i);
    for(int i = 0; i < N - 1; i++){
        min_ = min(min_, c[i]);
        ans += (long long)min_ * (long long)d[i];
    }
        
    printf("%lld", ans);
    return 0;
}