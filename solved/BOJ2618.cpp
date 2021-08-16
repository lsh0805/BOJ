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

int N, W, dp[1001][1001], ans[1001];
P p1, p2;
vector<P> v;

int get_distance(P u, P v){
	return abs(u.fi - v.fi) + abs(u.se - v.se);
}

int solve(int x, int y){
	int curr = max(x, y);
	P p1 = {1, 1}, p2 = {N, N};
	if(x != 0) p1 = v[x];
	if(y != 0) p2 = v[y];
	int & ret = dp[x][y];
	if(curr == W) return ret = 0;
	if(ret != 2e9) return ret;
	ret = solve(curr + 1, y) + get_distance(p1, v[curr + 1]);
	if(ret > solve(x, curr + 1) + get_distance(p2, v[curr + 1]))
		ret = solve(x, curr + 1) + get_distance(p2, v[curr + 1]);
	return ret;
}

void find(int x, int y){
	int curr = max(x, y);
	if(curr == W) return;
	P p1 = {1, 1}, p2 = {N, N};
	if(x != 0) p1 = v[x];
	if(y != 0) p2 = v[y];
	if(dp[curr + 1][y] == dp[x][y] - get_distance(p1, v[curr + 1])){
		ans[curr + 1] = 1;
		find(curr + 1, y);
	}else{
		ans[curr + 1] = 2;
		find(x, curr + 1);
	}
}

int main(){
    IO;
	cin >> N >> W;
	p1 = {1, 1};
	p2 = {N, N};
	v = vector<P>(W + 1);
	for(int i = 0; i <= W; i++){
		for(int j = 0; j <= W; j++){
			dp[i][j] = 2e9;
		}
	}
	for(int i = 0; i < W; i++){
		int a, b;
		cin >> a >> b;
		v[i + 1] = P(a, b);
	}
	cout << solve(0, 0) << "\n";
	find(0, 0);
	for(int i = 1; i <= W; i++){
		cout << ans[i] << "\n";
	}
    return 0;
}