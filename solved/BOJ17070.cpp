#include <stdio.h>
#include <vector>

using namespace std;

const int HORIZONTAL = 0, VERTICAL = 1, DIAGONAL = 2, IMPOSSIBLE = -1;
int tile[16][16], N;
// 가로, 세로, 대각선 방향, 마지막 인덱스에 있는 값은 다음 위치
vector<vector<vector<int>>> dx{{{1}, {IMPOSSIBLE}, {1, 0, 1}}, {{IMPOSSIBLE}, {0}, {1, 0, 1}}, {{1}, {0}, {1, 0, 1}}},
dy{{{0}, {IMPOSSIBLE}, {0, 1, 1}}, {{IMPOSSIBLE}, {1}, {0, 1, 1}}, {{0}, {1}, {0, 1, 1}}};

int solve(int y, int x, int prev){
    if(y == N - 1 && x == N - 1)
        return 1;
    int ret = 0;
    // 파이프를 놓을 방법만큼 반복돌림( 가로, 세로, 대각선 )
    for(int state = 0; state < 3; state++){
        // 해당 방법으로 놓는 것이 불가능하다면 건너뜀
        if(dx[prev][state][0] == IMPOSSIBLE) continue;
        bool flag = false;
        // 세팅 방법을 정했으면 해당 위치에 세팅하기 위해서 비어있어야 하는 곳 조사
        for(int i = 0; i < dx[prev][state].size(); i++){
            int nextX = x + dx[prev][state][i];
            int nextY = y + dy[prev][state][i];
            // 타일 밖이거나 빈 곳이 아닐 경우 건너뜀
            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || tile[nextY][nextX]) break;
            // 모든 곳이 다 비어있을 경우 flag 값 true로 변경
            if(i == dx[prev][state].size() - 1)
                flag = true;
        }
        // 모든 곳이 다 비어있었으면, 다음 파이프 끝 쪽으로 이동하여 다시 반복
        if(flag)
            ret += solve(y + dy[prev][state][dy[prev][state].size() - 1], x + dx[prev][state][dx[prev][state].size() - 1], state);
    }
    return ret;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &tile[i][j]);
    printf("%d", solve(0, 1, HORIZONTAL));
    return 0;
}