#include <stdio.h>
#include <utility>

using namespace std;

typedef pair<int, int> P;

int N, M, dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0}, visited[1001][1001], finished[1001][1001], cnt;
char c;
P adj[1001][1001];

int dfs(int y, int x){
  visited[y][x] = true;
  int result = -1;
  int nextY = adj[y][x].first, nextX = adj[y][x].second;
  if(!visited[nextY][nextX])
    result = dfs(nextY, nextX);
  else if(!finished[nextY][nextX])
    result = ++cnt;
  else
    result = finished[nextY][nextX];
  finished[y][x] = true;
  return result;
}

int main(){
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++){
    getchar();
    for(int j = 0; j < M; j++){
      c = getchar();
      int dir;
      switch (c)
      {
      case 'U':
        dir = 0;
        break;
      case 'D':
        dir = 1;
        break;
      case 'L':
        dir = 2;
        break;
      case 'R':
        dir = 3;
        break;
      default:
        break;
      }
      int nextY = i + dy[dir], nextX = j + dx[dir];
      adj[i][j] = P(nextY, nextX);
    }
  }
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      if(!visited[i][j])
        dfs(i, j);
  printf("%d", cnt);
  return 0;
}