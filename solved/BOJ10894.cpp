#include <stdio.h>

int T, N, a, sum1;
float b, sum2;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        sum1 = 0, sum2 = 0;
        for(int i = 0; i < N; i++){
            scanf("%d %f", &a, &b);
            sum1 += a;
            sum2 += a * b;
        }
        printf("%d %.1f\n", sum1, sum2/ sum1);
    }
    return 0;
}