#include <stdio.h>

int N, M, arr[101];

int main(){
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++)
    scanf("%d", arr + i);
  int ans = 0;
  for(int i = 0; i < N; i++)
    for(int j = i + 1; j < N; j++)
      for(int k = j + 1; k < N; k++){
        int sum = arr[i] + arr[j] + arr[k]; 
        if(sum <= M && ans < sum)
          ans = sum;
      }
  printf("%d", ans);
  return 0;
}