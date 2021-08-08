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

int N, m[10][10], ans, max_;
bool r[20], l[2][20];

int simulate(int x, int y){
	int nx = x + 2, ny = y, ret = 0;
	if(nx >= N) ny++, nx=!(nx%2);
	if(ny >= N) return 0;

	int r_o = (nx+ny)/2, l_o = (nx-ny)/2;
	
	if(m[ny][nx] && !r[r_o] && !l[(nx-ny) > 0][l_o]){
		r[r_o] = 1;
		l[(nx-ny) > 0][l_o] = 1;
		ret = 1 + simulate(nx, ny);
		r[r_o] = 0;
		l[(nx-ny) > 0][l_o] = 0;
	}
	return max(ret, simulate(nx, ny));
}

int main(){
    IO;
	cin >> N;
	FOR(i, 0, N)
		FOR(j, 0, N)
			cin >> m[i][j];
	max_ = simulate(0, 0);
	if(m[0][0]){
		r[0] = 1;
		l[0][0] = 1;
		max_ = max(max_, 1 + simulate(0, 0));
	}
	ans += max_;
	memset(r, false, sizeof(r));
	memset(l, false, sizeof(l));
	if(N >= 2){
		max_ = simulate(1, 0);
		if(m[0][1]){
			r[0] = 1;
			l[1][0] = 1;
			max_ = max(max_, 1 + simulate(1, 0));
		}
		ans += max_;
	}
	cout << ans;
    return 0;
}