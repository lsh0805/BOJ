#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> P;
queue<P> q, cheese_q;
int N, M, m[100][100], visited[100][100], dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}, level, ans, cheese;

void bfs(){
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){
            P curr = q.front();
            q.pop();
            int currY = curr.first;
            int currX = curr.second;
            for(int i = 0; i < 4; i++){
                int nextY = currY + dy[i];
                int nextX = currX + dx[i];
                if(nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visited[nextY][nextX]) continue;
                if(m[nextY][nextX]){
                    cheese_q.push(P(nextY, nextX));
                    cheese--;
                    m[nextY][nextX] = 0;
                }else
                    q.push(P(nextY, nextX));
                visited[nextY][nextX] = true;
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            scanf("%d", &m[i][j]);
            if(i == 0 || i == N - 1 || j == 0 || j == M - 1)
                q.push(P(i, j));
            cheese += m[i][j];
        }
    while(cheese){
        ans = cheese;
        level++;
        bfs();
        while(!cheese_q.empty()){
            q.push(cheese_q.front());
            cheese_q.pop();
        }
    }
    printf("%d\n%d", level, ans);
    return 0;
}