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

int N, a, b, c, dp[21][21][21];

int solve(int x, int y, int z){
	if(x <= 0 || y <= 0 || z <= 0) return 1;
	if(x > 20 || y > 20 || z > 20) return solve(20, 20, 20);
	int & ret = dp[x][y][z];
	if(ret != 0) return ret;
	if(x < y && y < z)
		return ret = solve(x, y, z - 1) + solve(x, y - 1, z - 1) - solve(x, y - 1, z);
	return ret = solve(x - 1, y, z) + solve(x - 1, y - 1, z) + solve(x - 1, y, z - 1) - solve(x - 1, y - 1, z - 1);
}

int main(){
    IO;
	while(true){
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << "\n";
		memset(dp, 0 , sizeof(dp));
	}
    return 0;
}