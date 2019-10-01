#include <stdio.h>

long long N, K;

int main(){
    scanf("%lld %lld", &N, &K);
    printf("%lld", (K / N + 1) * (K % N + 1));
    return 0;
}