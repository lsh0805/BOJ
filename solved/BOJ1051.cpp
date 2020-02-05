#include <stdio.h>

int N, M, ans = 1, max_s = 1;
char arr[51][51];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        getchar();
        for(int j = 0; j < M; j++)
            scanf("%c", &arr[i][j]);
    }
    for(int s_y = 0; s_y < N; s_y++){
        for(int s_x = 0; s_x < M; s_x++){
            for(int size = max_s + 1; true; size++){
                int e_y = s_y + size - 1;
                int e_x = s_x + size - 1;
                if(e_y >= N || e_x >= M) break;
                if(arr[s_y][s_x] == arr[e_y][e_x] && 
                arr[s_y][s_x] == arr[s_y][e_x] && arr[s_y][s_x] == arr[e_y][s_x]){
                    ans = size * size;
                    max_s = size;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}