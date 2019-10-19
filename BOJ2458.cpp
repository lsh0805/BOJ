#include <stdio.h>

int N, M, a, b, cnt[501], ans;
bool adj[501][501];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        --a, --b;
        adj[a][b] = true;
    }
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++){
            if(!adj[i][k]) continue;
            for(int j = 0; j < N; j++){
                adj[i][j] |= adj[i][k] && adj[k][j];
            }
        }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++)
            cnt[k] += adj[i][k] + adj[k][i];
        if(cnt[k] == N - 1)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}