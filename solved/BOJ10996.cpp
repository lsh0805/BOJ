#include <stdio.h>

int N;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N / 2 + N % 2; j++)
            printf("* ");
        if(N != 1)
            printf("\n ");
        for(int j = 0; j < N / 2; j++)
            printf("* ");
        putchar('\n');
    }
    return 0;
}