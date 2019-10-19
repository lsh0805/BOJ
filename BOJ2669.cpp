#include <stdio.h>

int x1, y1, x2 ,y2;
bool arr[101][101];

int main(){
    for(int i = 0; i < 4; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int i = y1; i < y2; i++)
            for(int j = x1; j < x2; j++)
                arr[i][j] = 1;
    }
    int ans = 0;
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
            ans += arr[i][j];
    printf("%d", ans);
    return 0;
}