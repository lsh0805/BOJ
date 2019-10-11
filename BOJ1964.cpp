#include <stdio.h>

int N, curr = 5;

int main(){
    scanf("%d", &N);
    for(int i = 1; i < N; i++){
        curr += (5 * (i + 1)) - (2 * i + 1);
        curr %= 45678;
    }
    printf("%d", curr);
    return 0;
}