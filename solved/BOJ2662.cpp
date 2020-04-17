#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int dp[301][21], N , M, benefit[301][21], cost;

int solve(int remain, int curr){
    int & ret = dp[remain][curr];
    if(ret != 0)
        return ret;
    if(curr == M - 1)
        return ret = benefit[remain][curr];
    for(int i = 0; i <= remain; i++)
        ret = max(solve(remain - i, curr + 1) + benefit[i][curr], ret);
    return ret;
}

void tracking(int curr, int remain, int total_b){
    if(curr == M)
        return;
    for(int i = 0; i <= remain; i++){
        if(dp[remain - i][curr + 1] + benefit[i][curr] == total_b){
            cout << i << " ";
            return tracking(curr + 1, remain - i, total_b - benefit[i][curr]);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> cost;
        for(int j = 0; j < M; j++){
            cin >> benefit[i][j];
        }
    }
    int ans = solve(N, 0);
    cout << ans << "\n";
    tracking(0, N, ans);
    return 0;
}