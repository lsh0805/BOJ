#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int ans, dp[31][31], N;
string str;

int solve(int st, int ed){
    int & ret = dp[st][ed];
    if(str[st] != str[ed])
        return ret = 0;
    if(ret != -1)
        return ret;
    ret = 1;
    for(int i = st + 1; i < ed; i++)
        for(int j = i; j < ed; j++)
                ret += solve(i, j);
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> str;
    memset(dp, -1, sizeof(dp));
    N = str.length();
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
                ans += solve(i, j);
    cout << ans;
    return 0;
}