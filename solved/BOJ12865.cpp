#include <bits/stdc++.h>

using namespace std;

int N, K, w[101], v[101], dp[100001][101];

int solve(int curr_w, int curr_idx){
  int & ret = dp[curr_w][curr_idx];
  if(ret != 0)
    return ret;
  for(int i = curr_idx + 1; i < N; i++)
    if(curr_w + w[i] <= K)
      ret = max(ret, solve(curr_w + w[i], i) + v[i]);
  return ret;
}

int main(){
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; i++)
    scanf("%d %d", w + i, v + i);
  int ans = 0;
  for(int i = 0; i < N; i++)
    if(w[i] <= K)
    ans = max(ans, solve(w[i], i) + v[i]);
  printf("%d", ans);
  return 0;
}