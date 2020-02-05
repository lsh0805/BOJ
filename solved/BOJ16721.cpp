#include <stdio.h>

int N, M, num, B, C;
char c;
int relation[3][5001];


int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++){
      scanf(" %c", &c);
      if(i < 3)
        relation[i][j] = c == '+';
    }
  scanf("%d", &M);
  for(int i = 0; i < M; i++){
    scanf("%d %d", &B, &C);
    int pivot = 0;
    if(B < 3 && C < 3)
      pivot = 3 - B - C;
    else if(B == pivot || C == pivot)
      pivot = 1;
    printf(relation[pivot][B] == relation[pivot][C] ? "+\n" : "-\n");
  }
  return 0;
}