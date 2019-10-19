#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;
P arr[501];
const int INF = 2e9;
int N, r, c, dp[501][501];

int solve(int start, int end){
    int & ret = dp[start][end];
    if(ret != 0)
        return ret;
    if(start == end)
        return ret = 0;
    if(start + 1 == end)
        return ret = arr[start].first * arr[start].second * arr[end].second;
    ret = INF;
    for(int i = start; i < end; i++)
        ret = min(ret, solve(start, i) + solve(i + 1, end) + (arr[start].first * arr[i].second * arr[end].second));
    return ret;
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &r, &c);
        arr[i] = P(r, c);
    }
    printf("%d", solve(0, N - 1));
    return 0;
}