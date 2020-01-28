#include <stdio.h>
#include <algorithm>

using namespace std;
const int N = 10, MAX_VALUE = 26;
int arr[10][10], ans = MAX_VALUE;

void solve(int y, int x, int * cnt){
    int cnt_sum = cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4];
    if(cnt_sum >= ans) return;
    if(y == N - 1 && x == N)
        ans = min(ans, cnt_sum);
    if(x == N)
        solve(y + 1, 0, cnt);
    if(arr[y][x] == 0)
        solve(y, x + 1, cnt);
    for(int size = 5; size > 0; size--){
        bool flag = true;
        if(cnt[size - 1] == 5)
            break;
        for(int next_y = y; next_y < y + size; next_y++){
            for(int next_x = x; next_x < x + size; next_x++){
                if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || arr[next_y][next_x] == 0){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag){
            for(int next_y = y; next_y < y + size; next_y++)
                for(int next_x = x; next_x < x + size; next_x++)
                    arr[next_y][next_x] = 0;
            cnt[size - 1]++;
            solve(y, x + size, cnt);
            cnt[size - 1]--;
            for(int next_y = y; next_y < y + size; next_y++)
                for(int next_x = x; next_x < x + size; next_x++)
                    arr[next_y][next_x] = 1;
        }
    }
}

int main(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    int cnt[5] = {0, 0, 0, 0, 0};
    solve(0, 0, cnt);
    printf("%d", ans == MAX_VALUE ? -1 : ans);
    return 0;
}