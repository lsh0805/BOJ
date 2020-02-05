#include <bits/stdc++.h>

using namespace std;

int N, M, arr[8];

void print(int idx, queue<int> q){
  q.push(idx);
  if(q.size() == M){
    while(!q.empty()){
      int front = q.front();
      q.pop();
      printf("%d ", arr[front]);
    }
    printf("\n");
    return;
  }
  for(int i = idx + 1; i < N - M + 1 + q.size(); i++){
    print(i, q);
  }
}

int main(){
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++)
    scanf("%d", arr + i);
  sort(arr, arr + N);
  for(int i = 0; i < N - M + 1; i++)
    print(i, queue<int>());
  return 0;
}