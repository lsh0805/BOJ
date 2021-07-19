#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, M, ans;
bool cache[10001][501][3];
char m[10001][501];

int simulate(int x, int y){
	if(x == M - 1){
		m[y][x] = 'x';
		return 1;
	}
	for (int i = -1; i < 2; i++)
	{
		int ny = y + i, nx = x + 1;
		if(ny < 0 || ny == N || cache[ny][nx][i + 1] == true) continue;
		if (m[ny][nx] == '.'){
			m[ny][nx] = 'x';
			if(simulate(x + 1, y + i))
				return 1;
			cache[ny][nx][i + 1] = true;
			m[ny][nx] = '.';
		}
	}
	return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> m[i][j];
	
	for(int i = 0; i < N; i++)
		ans += simulate(0, i);

	cout << ans << "\n";
    return 0;
}