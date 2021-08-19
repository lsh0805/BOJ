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

int K, a, b;
string s[4];

void rotate(int idx, int r){
	if(r == 1){
		char temp = s[idx][7];
		for(int i = 7; i > 0; i--){
			s[idx][i] = s[idx][i - 1];
		}
		s[idx][0] = temp;
	}
	if(r == -1){
		char temp = s[idx][0];
		for(int i = 0; i < 7; i++){
			s[idx][i] = s[idx][i + 1];
		}
		s[idx][7] = temp;
	}
}

void simul(int idx, int r, int dir){
	if(dir == -1){
		if(idx < 3 && s[idx][2] != s[idx + 1][6]){
			simul(idx + 1, r*-1, 1);
		}
		
		if(idx > 0 && s[idx][6] != s[idx - 1][2]){
			simul(idx - 1, r*-1, 0);
		}
	}
	if(dir == 0){
		if(idx > 0 && s[idx][6] != s[idx - 1][2]){
			simul(idx - 1, r*-1, 0);
		}
	}
	if(dir == 1){
		if(idx < 3 && s[idx][2] != s[idx + 1][6]){
			simul(idx + 1, r*-1, 1);
		}
	}
	rotate(idx, r);
}

int main(){
    IO;
	for(int i = 0; i < 4; i++){
		cin >> s[i];
	}
	cin >> K;
	for(int i = 0; i < K; i++){
		cin >> a >> b;
		simul(a - 1, b, -1);
		// for(int i = 0; i < 4; i++){
		// 	cout << s[i] << "\n";
		// }
	}
	int ans = 0, pow = 1;
	for(int i = 0; i < 4; i++){
		if(s[i][0] == '1'){
			ans += pow;
		}
		pow*=2;
	}
	cout << ans << '\n';
    return 0;
}