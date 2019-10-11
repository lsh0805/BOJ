#include <stdio.h>

int arr[1000][1000], N, num, ans_x, ans_y;
const int DOWN = 0, RIGHT = 1, UP = 2, LEFT = 3;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void process(int curr_x, int curr_y, int val, int dir){
    arr[curr_y][curr_x] = val;
    if(val == num){
        ans_x = curr_x + 1;
        ans_y = curr_y + 1;
    }
    if(val == 1) return;
    int next_x = curr_x + dx[dir];
    int next_y = curr_y + dy[dir];
    if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || arr[next_y][next_x] != 0){
        dir = (dir + 1) % 4;
        next_x = curr_x + dx[dir];
        next_y = curr_y + dy[dir];
    }
    process(next_x, next_y, val - 1, dir);
}

int main(){
    scanf("%d %d", &N, &num);
    process(0, 0, N * N, DOWN);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("%d %d", ans_y, ans_x);
    return 0;
}