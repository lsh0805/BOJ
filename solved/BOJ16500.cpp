#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, dp[100];
string s, a[100];

bool solve(int curr){
	int & ret = dp[curr];
	if(curr == s.length())
		return ret = true;
	if(dp[curr] != -1)
		return dp[curr];
	ret = false;
	for(int i = 0; i < N; i++){
		if(curr + a[i].length() > s.length()) continue;
		if(s.substr(curr, a[i].length()).compare(a[i]) == 0){
			ret |= solve(curr + a[i].length());
			if(ret == true) return true;
		}
	}
	return ret = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> s >> N;
	for(int i = 0; i < s.length(); i++)
		dp[i] = -1;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	cout << solve(0);
    return 0;
}