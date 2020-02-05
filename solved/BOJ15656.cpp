#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int N, M, arr[8];

void print(int idx){
  if(v.size() == M){
    for(int i = 0; i < v.size(); i++)
      printf("%d ", v[i]);
    printf("\n");
    return;
  }
  for(int i = 0; i < N; i++){
    v.push_back(arr[i]);
    print(i);
    v.pop_back();
  }
}

int main(){
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++)
    scanf("%d", arr + i);
  sort(arr, arr + N);
  for(int i = 0; i < N; i++){
    v.push_back(arr[i]);
    print(i);
    v.pop_back();
  }
}