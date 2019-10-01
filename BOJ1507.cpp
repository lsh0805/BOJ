#include <stdio.h>
#include <algorithm>

using namespace std;

int N, dist[21][21], dist2[21][21], ans;
const int INF = 1e9;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            scanf("%d", &dist[i][j]);
            if(i == j)
                dist[i][j] = INF;
            dist2[i][j] = INF;
        }
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dist2[i][j] = min(dist2[i][j], dist[i][k] + dist[k][j]);
    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++){
            if(dist2[i][j] < dist[i][j]){
                printf("-1");
                return 0;
            }
            if(dist2[i][j] != dist[i][j])
                ans += dist[i][j];
        }
    printf("%d", ans);
    return 0;
}