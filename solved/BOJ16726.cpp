#include <stdio.h>

int N, M, blank, graph[51][51];
const int BLANK = 1, BLOCK = 2;

bool check(int cnt, int y, int x){
  if(x == M){
    if(y == N - 1){
      return cnt == 0;
    }else{
      return check(cnt, y + 1, 0);
    }
  }
  bool ret = false;
  if(graph[y][x] == BLANK){
    if(graph[y][x + 1] == BLANK){
      graph[y][x] = BLOCK;
      graph[y][x + 1] = BLOCK;
      ret = check(cnt - 1, y, x + 1);
      graph[y][x] = BLANK;
      graph[y][x + 1] = BLANK;
    }
    if(graph[y + 1][x] == BLANK){
      graph[y][x] = BLOCK;
      graph[y + 1][x] = BLOCK;
      ret = ret || check(cnt - 1, y, x + 1);
      graph[y][x] = BLANK;
      graph[y + 1][x] = BLANK;
    }
  }
  return ret || check(cnt, y, x + 1);
}

int main(){
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++){
    getchar();
    for(int j = 0; j < M; j++){
      graph[i][j] = getchar() == 'X' ? BLOCK : BLANK;
      blank += graph[i][j] == BLANK;
    }
  }
  int left = 0, right = blank / 2;
  while(left + 1 < right){
    int mid = (left + right) / 2;
    if(!check(mid, 0, 0)){
      right = mid;
    }else{
      left = mid;
    }
  }
  if(check(right, 0, 0))
    left = right;
  printf("%d", left + (blank - left * 2));
  return 0;
}