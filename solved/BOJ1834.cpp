#include <stdio.h>

long long N, ans;

int main(){
    scanf("%lld", &N);
    for(long long i = N + 1; (i % N != 0); i += N + 1)
        ans += i;
    printf("%lld", ans);
    return 0;
}