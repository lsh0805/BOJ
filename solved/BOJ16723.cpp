#include <stdio.h>

long long sum, N;

int main(){
  scanf("%lld", &N);
  sum = 2 * N;
  for(long long i = 4; i <= (2 * N); i *= 2)
    sum += (i/2) * (2 * N / i);
  printf("%lld", sum);
  return 0;
}