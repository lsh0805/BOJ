#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M, D, graph[15][15], ans, enemy_cnt;

int getDist(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int simulate(int * arr, int enemy_size){
    int copy_graph[15][15] = {0};
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            copy_graph[i][j] = graph[i][j];
    int ret = 0;
    // 적이 한 명이라도 있으면 계속 반복함.
    while(enemy_size > 0){
        int bestDist[3] = {1000, 1000, 1000}, bestX[3] = {-1, -1, -1}, bestY[3] = {-1, -1, -1};
        // 궁수 크기만큼 반복문 돌림 (3명)
        for(int i = 0; i < 3; i++){
            for(int x = 0; x < M; x++){
                for(int y = N - 1; y >= 0; y--){
                    int dist = getDist(arr[i], N, x, y);
                    // 해당 위치에 적이 없거나 적과의 거리차이가 D보다 크다면 건너뜀
                    if(!copy_graph[y][x] || dist > D) continue;
                    // 거리차이가 더 작은 것일 경우 갱신 (x값 반복이 작은 거에서부터 커지므로 등호 붙이면 가장 왼쪽에 있는 적 보장 안 됨)
                    if(dist < bestDist[i]){
                        bestDist[i] = dist;
                        bestY[i] = y;
                        bestX[i] = x;
                    }
                }
            }
        }
        // 각 궁수에게 가장 가까운 적을 발견했다면 해당 적을 지움, 다른 궁수에게 이미 공격당한 경우는 무시해야함
        for(int i = 0; i < 3; i++){  
            if(bestX[i] != -1 && bestY[i] != -1 && copy_graph[bestY[i]][bestX[i]]){
                copy_graph[bestY[i]][bestX[i]] = 0;
                enemy_size--;
                ret++;
            }
        }
        for(int y = N - 1; y >= 0; y--){
            for(int x = 0; x < M; x++){
                // 모든 적 찾아서 한 칸씩 내림, 성문에 도착하면 아예 삭제함
                if(copy_graph[y][x]){
                    copy_graph[y][x] = 0;
                    if(y + 1 != N)
                        copy_graph[y + 1][x] = 1;
                    else
                        enemy_size--;
                }
            }
        }
    }
    return ret;
}

int main(){
    scanf("%d %d %d", &N, &M, &D);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            scanf("%d", &graph[i][j]);
            enemy_cnt += graph[i][j];
        }
    for(int a = 0; a < M; a++){
        for(int b = 0; b < M; b++){
            for(int c = 0; c < M; c++){
                if(a == b || a == c || b == c) continue;
                int arr[3] = {a, b, c};
                ans = max(ans, simulate(arr, enemy_cnt));
            }
        }
    }
    printf("%d", ans);
    return 0;
}