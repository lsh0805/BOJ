#include <bits/stdc++.h>

int N, M, B, block[501][501];

int main(){
    scanf("%d %d %d", &N, &M, &B);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &block[i][j]);
    int min_time = 2e9, min_height = 2e9;
    for(int pivot = 0; pivot <= 256; pivot++){
        int time = 0, curr_cnt = B;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(pivot > block[i][j]){
                    time += pivot - block[i][j];
                    curr_cnt -= pivot - block[i][j];
                }else if(pivot < block[i][j]){
                    time += (block[i][j] - pivot) * 2;
                    curr_cnt += block[i][j] - pivot;
                }
        if(curr_cnt >= 0 && min_time >= time){
            min_time = time;
            min_height = pivot;
        }
    }
    printf("%d %d", min_time, min_height);
    return 0;
}