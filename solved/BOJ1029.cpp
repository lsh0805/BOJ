#include <bits/stdc++.h>

using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define FOR(x, i, n) for(int x = i; x < n; x++)
#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, cost[20][20],dp[1024*32][15][10];
char c;

int solve(int visit, int idx, int curr){
	int & ret = dp[visit][idx][curr];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i < N; i++){
		if((visit & (1 << i)) != 0) continue;
		if(cost[idx][i] < curr) continue;
		ret = max(ret, solve(visit | (1 << i), i, max(curr, cost[idx][i])) + 1);
	}
	return ret;
}

int main(){
    IO;
	cin >> N;
	for(int i = 0; i < (1 << 15); i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < 10; k++){
				dp[i][j][k] = -1;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> c;
			cost[i][j] = c - '0';
		}
	}
	cout << solve(1, 0, 0) + 1 << "\n";
    return 0;
}