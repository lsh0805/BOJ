#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<P, P> PP;

const int INF = 2e9;
const int R = 0;
const int B = 1;
int N, M, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}, ans = INF;
char m[10][10];
P pos[2];

void tilt(int dx, int dy){
	int first = 0;
	if(P(pos[R].fi + dy, pos[R].se + dx) == pos[B])
		first = 1;
	int over = 0;
	while(true){
		for(int i = first; i < 2 && i >= 0; i += 1 + -2 * first)
		{
			if((over & 1 << i) != 0) continue;
			if(m[pos[i].fi + dy][pos[i].se + dx] == '#' || P(pos[i].fi + dy, pos[i].se + dx) == pos[!i])
			{
				over |= 1 << i;
			}
			else if(m[pos[i].fi + dy][pos[i].se + dx] == 'O')
			{
				if (i == R)
				{
					pos[0].fi = -1;
					over |= 1 << i;
				}
				else if (i == B)
				{
					pos[0].fi = -2;
					return;
				}
			}
			else
			{
				pos[i].fi += dy;
				pos[i].se += dx;
			}
		}
		if (over == 3)
			break;
		
	}
}

int simulate(int cnt){
	int res = INF;
	if(cnt == 10 || cnt >= ans) return res;
	P origin[2] = {pos[0], pos[1]};
	for (int i = 0; i < 4; i++){
		tilt(dx[i], dy[i]);
		if(pos[0].fi == -1){
			ans = min(ans, cnt + 1);
			return cnt + 1;
		}
		else if(pos[0].fi != -2)
			res = min(res, simulate(cnt + 1));
		pos[0] = origin[0];
		pos[1] = origin[1];
	}
	return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		
		for(int j = 0; j < M; j++)
		{
			cin >> m[i][j];
			if(m[i][j] == 'R'){
				pos[R].fi = i;
				pos[R].se = j;
			}
			if(m[i][j] == 'B'){
				pos[B].fi = i;
				pos[B].se = j;
			}
		}
	}
	simulate(0);
	cout << (ans == INF ? -1 : ans);
    return 0;
}