#include <stdio.h>

int N, M;

void printBit(int bit){
    for(int i = 0; i < N; i++){
        if(bit & (1 << i))
            printf("%d ", i + 1);
    }
    putchar('\n');
}

void process(int bit, int idx, int cnt){
    if(cnt == M){
        printBit(bit);
        return;
    }
    for(int i = idx + 1; i <= N; i++){
        process(bit | (1 << (i - 1)), i, cnt+1);
    }

}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        process(1 << (i - 1), i, 1);
    }
    return 0;
}