#include <stdio.h>

int T, N;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 0; N; i++){
            if(N % 2 == 1)
                printf("%d ", i);
            N >>= 1;
        }
        printf("\n");
    }
    return 0;
}