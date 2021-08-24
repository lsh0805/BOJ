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

int N, L, m[101][101], dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}, s[2][101][101];
bool r[101], c[101];

bool set_up(int x, int y, int dir){
	bool horizontal = false;
	if(dx[dir] != 0)
		horizontal = true;
	for(int i = 0; i < L; i++){
		int ny = y + dy[dir] * i, nx = x + dx[dir] * i;
		if(nx < 0 || nx >= N || ny < 0 || ny >= N) return false;
		if((m[y][x] != m[ny][nx]) || s[horizontal][ny][nx]) return false;
	}
	
	for(int i = 0; i < L; i++){
		int ny = y + dy[dir] * i, nx = x + dx[dir] * i;
		s[horizontal][ny][nx] = dir + 1;
	}
	return true;
}

void simulate(int dir){
	int x = 0, y = 0;
	
	for(int i = 0; i < N; i++){
		if(dir == 0)
			y = N - 1;
		if(dir == 1)
			y = 0;
		if(dir == 2)
			x = N - 1;
		if(dir == 3)
			x = 0;
		if(dx[dir] != 0)
			y = i;
		if(dy[dir] != 0)
			x = i;
		bool flag = true;
		while(true){
			int nx = x + dx[dir], ny = y + dy[dir];
			if(nx < 0 || nx >= N || ny < 0 || ny >= N) break;
			if(m[y][x] - m[ny][nx] == 1){
				if(!set_up(nx, ny, dir)){
					flag = false;
					break;
				}
			}
			else if(abs(m[ny][nx] - m[y][x]) > 1){
				flag = false;
				break;
			}
			y = ny, x = nx;
		}
		// if(flag == false){
		// 	if(dir == 0)
		// 		y = N - 1;
		// 	if(dir == 1)
		// 		y = 0;
		// 	if(dir == 2)
		// 		x = N - 1;
		// 	if(dir == 3)
		// 		x = 0;
		// 	if(dx[dir] != 0)
		// 		y = i;
		// 	if(dy[dir] != 0)
		// 		x = i;
		// 	while(true){
		// 		if(s[y][x] == dir + 1) s[y][x] = 0;
		// 		x += dx[dir], y += dy[dir];
		// 		if(x < 0 || x >= N || y < 0 || y >= N) break;
		// 	}
		// }
	}
}

int get_count(){
	int ans = 0;
	bool horizontal = false;
	memset(r, true, sizeof(r));
	memset(c, true, sizeof(c));
	for(int dir = 0; dir < 4; dir++){
		int x = 0, y = 0;
		for(int i = 0; i < N; i++){
			if(dir == 0)
				y = N - 1;
			if(dir == 1)
				y = 0;
			if(dir == 2)
				x = N - 1;
			if(dir == 3)
				x = 0;
			if(dx[dir] != 0){
				y = i;
				horizontal = true;
			}
			if(dy[dir] != 0)
				x = i;
			while(true){
				int nx = x + dx[dir], ny = y + dy[dir];
				if(nx < 0 || nx >= N || ny < 0 || ny >= N) break;
				if(m[y][x] - m[ny][nx] == 1){
					if(s[horizontal][ny][nx] == dir + 1){
						y += dy[dir] * L;
						x += dx[dir] * L;
						continue;
					}else{
						if(dx[dir] != 0)
							r[i] = false;
						if(dy[dir] != 0)
							c[i] = false;
						break;
					}
				}
				if(abs(m[y][x] - m[ny][nx]) > 1){
					if(dx[dir] != 0)
						r[i] = false;
					if(dy[dir] != 0)
						c[i] = false;
					break;
				}
				y = ny, x = nx;
			}
		}
	}
	for(int i = 0; i < N; i++){
		if(r[i]){
			// cout << "r : " << i << "\n";
			ans++;
		}
		if(c[i]){
			// cout << "c : " << i << "\n";
			ans++;
		}
	}
	return ans;
}

int main(){
    IO;
	cin >> N >> L;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> m[i][j];
		}
	}
	for(int dir = 0; dir < 4; dir++)
		simulate(dir);
	cout << get_count();
    return 0;
}