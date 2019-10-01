#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M, K, a, b, c, ans, cnt[251][251];
const int INF = 1e8;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        cnt[i][i] = 0;
        for(int j = 0; j < N; j++)
            if(i != j)
                cnt[i][j] = INF;
    }
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        cnt[a][b] = 0;
        if(c == 1)
            cnt[b][a] = 0;
        else
            cnt[b][a] = 1;
    }
    
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++){
            if(cnt[i][k] == INF) continue;
            for(int j = 0; j < N; j++)
                cnt[i][j] = min(cnt[i][j], cnt[i][k] + cnt[k][j]);
        }
    scanf("%d", &K);
    while(K--){
        scanf("%d %d", &a, &b);
        --a, --b;
        printf("%d\n", cnt[a][b]);
    }
    return 0;
}