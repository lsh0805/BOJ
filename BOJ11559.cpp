#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> P;
queue<P> group;
char m[12][6];
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}, ans;
bool visited[12][6];

void dfs(int x, int y){
    visited[y][x] = true;
    group.push(P(y, x));
    for(int i = 0; i < 4; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX < 0 || nextX >= 6 || nextY < 0 || nextY >= 12 || visited[nextY][nextX] || m[y][x] != m[nextY][nextX]) continue;
        dfs(nextX, nextY);
    }
}
void gravity(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 12; j++){
            while(m[j][i] == 'x'){
                for(int k = j; k > 0; k--){
                    m[k][i] = m[k - 1][i];
                }
                m[0][i] = '.';
            }
        }
    }
}

int main(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            m[i][j] = getchar();
        }
        getchar();
    }
    while(true){
        bool flag = false;
        group = queue<P>();
        for(int i = 0; i < 12; i++)
            for(int j = 0; j < 6; j++)
                visited[i][j] = false;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                group = queue<P>();
                if(!visited[i][j] && (m[i][j] == 'R' || m[i][j] == 'G' || m[i][j] == 'B' || m[i][j] == 'P' || m[i][j] == 'Y')){
                    dfs(j, i);
                    if(group.size() >= 4){
                        flag = true;
                        while(!group.empty()){
                            m[group.front().first][group.front().second] = 'x';
                            group.pop();
                        }
                    }
                }
            }
        }
        if(flag)
            ans++;
        else
            break;
        gravity();
    }
    printf("%d", ans);
    return 0;
}