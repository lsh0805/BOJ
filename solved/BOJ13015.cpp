#include <stdio.h>

int N;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        putchar('*');
    }
    for(int i = 0; i < 1 + (N - 2) * 2; i++){
        putchar(' ');
    }
    for(int i = 0; i < N; i++){
        putchar('*');
    }
    putchar('\n');
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j <= i; j++){
            putchar(' ');
        }
        putchar('*');
        for(int j = 0; j < N-2; j++){
            putchar(' ');
        }
        putchar('*');
        for(int j = 0; j < 2 *(N - 2 - i ) - 1; j++){
            putchar(' ');
        }
        if(i != N-2)
            putchar('*');
        for(int j = 0; j < N-2; j++){
            putchar(' ');
        }
        putchar('*');
            putchar('\n');
    }
    for(int i = 0; i < N - 2; i++){
        for(int j = N - 2 - i; j > 0; j--){
            putchar(' ');
        }
        putchar('*');
        for(int j = 0; j < N-2; j++){
            putchar(' ');
        }
        putchar('*');
        for(int j = 0; j < (i + 1) * 2 - 1; j++){
            putchar(' ');
        }
        putchar('*');
        for(int j = 0; j < N-2; j++){
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
    for(int i = 0; i < N; i++){
        putchar('*');
    }
    for(int i = 0; i < 1 + (N - 2) * 2; i++){
        putchar(' ');
    }
    for(int i = 0; i < N; i++){
        putchar('*');
    }
    return 0;
}