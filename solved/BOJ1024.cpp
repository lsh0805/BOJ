#include <stdio.h>

int N, L;

int main(){
  scanf("%d %d", &N, &L);
  for(int i = L; i <= 100; i++){
    int pivot = N / i - (i / 2);
    if(i % 2 == 1){
      if(N % i != 0)
        continue;
    }else if(i % 2 == 0){
      pivot++;
      if(N % i != i / 2)
        continue;
    }
    if(pivot < 0) continue;
    for(int j = pivot; j < pivot + i; j++)
      printf("%d ", j);
    return 0;
  }
  printf("-1");
  return 0;
}