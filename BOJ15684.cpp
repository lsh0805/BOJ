#include <stdio.h>

int N, M, H, a, b, currX[11];
bool edge[31][11];

bool check(){
    for(int i = 0; i < N; i++){
        int currX = i;
        for(int y = 0; y < H; y++){
            if(currX < N - 1 && edge[y][currX])
                currX++;
            else if(currX > 0 && edge[y][currX - 1])
                currX--;
        }
        if(currX != i) return false;
    }
    return true;
}

bool solve(int y, int x, int cnt){
    if(x == N && y == H - 1)
        return false;
    if(x == N)
        return solve(y + 1, 0, cnt);
    if(cnt == 0)
        return check();
    int ret = false;
    if((x == 0 || !edge[y][x - 1]) && !edge[y][x] && (x == N - 1 || !edge[y][x + 1])){
        edge[y][x] = true;
        ret |= solve(y, x + 1, cnt - 1);
        edge[y][x] = false;
    }
    return ret | solve(y, x + 1, cnt);
}

int main(){
    scanf("%d %d %d", &N, &M, &H);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        edge[a - 1][b - 1] = true;
    }
    if(check()){
        printf("0");
        return 0;
    }
    for(int i = 1; i <= 3; i++){
        if(solve(0, 0, i)){
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}