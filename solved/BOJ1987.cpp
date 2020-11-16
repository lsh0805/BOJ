#include <iostream>

using namespace std;

int N, a[2001], Q, S, E, dp[2001][2001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a[i];
		dp[i][0] = true;
	}
	cin >> Q;
	for(int j = 1; j < N; j++){
		for(int i = 0; i + j < N; i++){
			if(j == 1)
				dp[i][j] = (a[i] == a[i + j]);
			else
				dp[i][j] = (a[i] == a[i + j]) && dp[i + 1][j - 2];
		}
	}
	for(int i = 0; i < Q; i++){
		cin >> S >> E;
		cout << dp[S - 1][E - S] << "\n";
	}
	return 0;
}