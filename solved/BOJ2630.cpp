#include <stdio.h>
#include <utility>

using namespace std;

typedef pair<int, int> P;

int N, arr[128][128];

bool check(int y, int x, int size){
  int color = arr[y][x];
  for(int i = y; i < y + size; i++)
    for(int j = x; j < x + size; j++)
      if(arr[i][j] != color)
        return false;
  return true;
}

P solve(int y, int x, int size){
  if(check(y, x, size)){
    return P(arr[y][x] == 1, arr[y][x] == 0);
  }else{
    P ul = solve(y, x, size / 2);
    P ur = solve(y, x + size / 2, size / 2);
    P dl = solve(y + size / 2, x, size / 2);
    P dr = solve(y + size / 2, x + size / 2, size / 2);
    return P(ul.first + ur.first + dl.first + dr.first, ul.second + ur.second + dl.second + dr.second);
  }
}

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      scanf("%d", &arr[i][j]);
  P ans = solve(0, 0, N);
  printf("%d\n%d", ans.second, ans.first);
  return 0;
}