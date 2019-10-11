#include <stdio.h>

int N, M, used[9];

void process(int curr, int cnt){
    if(cnt == M){
        for(int i = 1; i <= N; i++){
            for(int j = 0; j < used[i]; j++){
                printf("%d ", i);
            }
        }
        printf("\n");
        return;
    }
    for(int i = curr; i <= N; i++){
        used[i]++;
        process(i, cnt + 1);
        used[i]--;
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        used[i]++;
        process(i, 1);
        used[i]--;
    }
    return 0;
}