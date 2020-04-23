#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
int N, L, R;
ll dp[101][101][101];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> L >> R;
    dp[1][1][1] = 1;
    for(int n = 2; n <= N; n++){
        for(int l = 1; l <= L; l++){
            for(int r = 1; r <= R; r++){
                dp[n][l][r] = dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1] + dp[n - 1][l][r] * (n - 2);
                dp[n][l][r] %= MOD;
            }
        }
    }
    cout << dp[N][L][R];
    return 0;
}