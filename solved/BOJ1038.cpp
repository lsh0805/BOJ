#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, pair<int, int>> p2;
typedef vector<int> vi;

int T, N, ans, dp[11][10];

int solve(int idx, int num){
    int & ret = dp[idx][num];
    if(idx == 0)
        return ret = 1;
    if(ret != -1)
        return ret;
    ret = 0;
    for(int next = num - 1; idx > 0 && next >= 0; next--)
        ret += solve(idx - 1, next);
    return ret;
}

void tracking(int idx, int num, int remain){
    cout << num;
    if(idx == 0)
        return;
    int sum = 0;
    for(int next = 0; next < num; next++){
        if(sum + dp[idx - 1][next] >= remain){
            tracking(idx - 1, next, remain - sum);
            return;
        }else{
            sum += dp[idx-1][next];
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    int sum = 0;
    bool flag = false;
    int prev, idx;
    if(N == 0){
        cout << 0;
        return 0;
    }
    for(idx = 0; idx < 11; idx++){
        for(prev = 1; prev < 10; prev++){
            solve(idx, prev);
            if(sum + dp[idx][prev] >= N){
                flag = true;
                break;
            }else{
                sum += dp[idx][prev];
                if(idx == 10 && prev == 9){
                    cout << "-1";
                    return 0;
                }
            }
        }
        if(flag) break;
    }
    tracking(idx, prev, N - sum);
    
    return 0;
}