#include <stdio.h>
#include <algorithm>

using namespace std;

int a, b, c, N, M, dist[401][401];
const int INF = 1e8;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            dist[i][j] = INF;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        dist[a][b] = c;
    }
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++){
            if(dist[i][k] == INF) continue;
            for(int j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    int ans = INF;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            ans = min(ans, dist[i][j] + dist[j][i]);
    if(ans == INF)
        printf("-1\n");
    else
        printf("%d", ans);
    return 0;
}