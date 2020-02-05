#include <stdio.h>

int N, arr[10][10];

//height : 2^N - 1;

void rtriangle(int size, int x, int y, int curr_height);

void triangle(int size, int x, int y, int curr_height){
    int height = 1 << size - 1;
    if(size == 0 || height == y)
        return;
    int space = height - curr_height;
    arr[y][x + space] = 1;
    if(y == height / 2 + 1)
        rtriangle(size - 1, x + 1, y, 0);
    if(curr_height != 0)
        arr[y][x + 2 * curr_height + 1] = 1;
    triangle(size, 0, y + 1, curr_height + 1);
}

void rtriangle(int size, int x, int y, int curr_height){
    int height = 1 << size - 1;
    if(size == 0 || height == y)
        return;
    int space = curr_height - 1;
    arr[y][x + space] = 1;
    if(y == height / 2 + 1)
        triangle(size - 1, x + 1, y, 0);
    if(curr_height != 0)
        arr[y][x + 2 * (height - curr_height) + 1] = 1;
    rtriangle(size, 0, y + 1, curr_height + 1);
}
int main(){
    scanf("%d", &N);
    if(N % 2)
        triangle(N, 0, 0, 0);
    else
        rtriangle(N, 0, 0, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            if(arr[i][j])
                putchar('*');
            else
                putchar(' ');
        putchar('\n');
    }

    return 0;
}