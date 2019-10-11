#include <stdio.h>

int N, T;
long long num, a, b;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%lld %d", &num, &N);
        while(N--){
            scanf("%lld %lld", &a, &b);
            num += a * b;
        }
        printf("%lld\n", num);
    }
    return 0;
}