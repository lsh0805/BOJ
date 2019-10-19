#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M, cnt;
char arr[51][51];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        getchar();
        for(int j = 0; j < M; j++){
            arr[i][j] = getchar();
        } 
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == 'X'){
                cnt += 1;
                break;
            }
        }
    }
    int row = N - cnt;
    cnt = 0;
    for(int j = 0; j < M; j++)
        for(int i = 0; i < N; i++){
            if(arr[i][j] == 'X'){
                cnt += arr[i][j] == 'X';
                break;
            }
        }
    int col = M - cnt;
    int ans = max(row, col);
    printf("%d\n", ans);
    return 0;   
}