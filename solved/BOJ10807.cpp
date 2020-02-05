#include <stdio.h>

int cnt[201], N, v, a;
int main(){
    scanf("%d", &N);
    while(N--){
        scanf("%d", &a);
        cnt[a + 100]++;
    }
    scanf("%d", &v);
    printf("%d", cnt[v + 100]);
    return 0;
}