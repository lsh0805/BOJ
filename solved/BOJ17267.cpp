#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct State{
    int l, r, y, x;
};

bool visited[1001][1001];
int N, M, L, R, ans, startX, startY;
char m[1001][1001];
int dy[2] = {-1, 1};
queue<State> q;


bool check(int y, int x){
    return (x < 0 || x >= M || y < 0 || y >= N || visited[y][x] || m[y][x] == '1');
}
int main(){
    scanf("%d %d %d %d", &N, &M, &L, &R);
    for(int i = 0; i < N; i++){
        getchar();
        for(int j = 0; j < M; j++){
            scanf("%c", &m[i][j]);
            if(m[i][j] == '2'){
                q.push({L, R, i, j});
                visited[i][j] = true;
            }
        }
    }
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){
            State curr = q.front();
            q.pop();
            int currL = curr.l;
            int currR = curr.r;
            int currY = curr.y;
            int currX = curr.x;
            for(int j = 0; j < 2; j++){
                int nextY = currY;
                while(true){
                    nextY += dy[j];
                    if(check(nextY, currX)) break;
                    q.push({currL, currR, nextY, currX});
                    visited[nextY][currX] = true;
                }
            }
            if(currL != 0 && !check(currY, currX - 1)){
                q.push({currL - 1, currR, currY, currX - 1});
                visited[currY][currX - 1] = true;
            }
            if(currR != 0 && !check(currY, currX + 1)){
                q.push({currL, currR - 1, currY, currX + 1});
                visited[currY][currX + 1] = true;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            ans += visited[i][j];
        }
    }
    printf("%d\n", ans);
    return 0;
}