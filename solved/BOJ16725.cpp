#include <stdio.h>

const int MOD = 1e9;
int dp[501][25001], N, M, K;

int solve(int power, int idx){
  for(int i = 0; i < N; i++){

  }
}


int main(){
  scanf("%d %d %d", &N, &M, &K);
  
  for(int i = 0; i <= N; i++)
    accumulate[i][1] = 1;
  
  for(int i = 2; i <= M; i++){
    for(int j = 0; j <= N * (i - 1); j++){
      for(int k = 0; k <= N; k++){
        accumulate[j + k][i] += accumulate[j][i - 1];
        accumulate[j + k][i] %= MOD;
      }
    }
  }
  printf("%d\n", accumulate[K][M]);
  return 0;
}