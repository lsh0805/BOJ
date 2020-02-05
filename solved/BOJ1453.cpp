#include <stdio.h>

int arr[101], N, num, cnt;

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &num);
    cnt += arr[num];
    arr[num] = 1;
  }
  printf("%d", cnt);
}