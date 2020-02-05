#include <stdio.h>
using namespace std;

int T, N, M, a, b;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < M; i++)
            scanf("%d %d", &a, &b);
        printf("%d\n", N - 1);
    }
    return 0;
}