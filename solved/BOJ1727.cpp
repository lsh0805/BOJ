#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, M, a[1001], b[1001], dp[1001][1001], ans;

int solve(int curr_a, int curr_b){
    if(curr_a == N - 1)
        return abs(a[curr_a] - b[curr_b]);
    int & ret = dp[curr_a][curr_b];
    if(ret != -1)
        return ret;
    ret = 2e9;
    for(int i = curr_b + 1; i < M; i++)
        ret = min(ret, solve(curr_a + 1, i) + abs(a[curr_a] - b[curr_b]));
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    for(int i = 0; i < M; i++)
        cin >> b[i];
    if(N > M){
        swap(N, M);
        swap(a, b);
    }
    memset(dp, -1, sizeof(dp));
    sort(a, a + N);
    sort(b, b + M);
    ans = 2e9;
    for(int i = 0; i < M; i++)
        ans = min(ans, solve(0, i));
    cout << ans << "\n";
    return 0;
}