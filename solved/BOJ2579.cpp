#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = -100000000;

int N, dp[301][2], s[301];

int solve(int idx, bool before) {
    if(idx == N)
        return s[idx];
    else if(idx > N)
        return INF;
    int & ret = dp[idx][before];
    if(ret != 0)
        return ret;
    ret = s[idx];
    if(!before)
        ret = max(ret + solve(idx + 1, true), ret + solve(idx + 2, false));
    else
        ret = ret + solve(idx + 2, false);
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) 
		scanf("%d", &s[i]);
	printf("%d\n", max(solve(1, false), solve(2, false)));
	return 0;
}