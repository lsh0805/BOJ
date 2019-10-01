#include <stdio.h>
#include <algorithm> 

using namespace std;

int N, M, S, dist[401][401], a, b;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        --a, --b;
        dist[a][b] = 1;
    }
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++){
            if(dist[i][k] == false) continue; 
            for(int j = 0; j < N; j++){
                if(dist[i][j] == true) continue;
                dist[i][j] = dist[i][k] && dist[k][j];
            }
        }
    scanf("%d", &S);
    while(S--){
        scanf("%d %d", &a, &b);
        --a, --b;
        if(!(dist[a][b] || dist[b][a]))
            printf("0");
        else if(dist[b][a])
            printf("1");
        else
            printf("-1");
        putchar('\n');
    }
    return 0;
}