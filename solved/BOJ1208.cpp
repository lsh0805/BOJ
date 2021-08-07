#include <bits/stdc++.h>

using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, S, a[40];
ll ans;
vector<int> v[2];

int main(){
    IO;
	cin >> N >> S;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	int mid = N / 2;
	for(int i = 1; i < (1 << mid); i++){
		int temp = i, sum = 0, j = 0;
		while(temp){
			if(temp % 2) sum += a[j];
			temp >>= 1;
			j++;
		}
		if(sum == S) ans++;
		v[0].push_back(sum);
	}
	for(int i = 1; i < (1 << (N - mid)); i++){
		int temp = i, sum = 0, j = 0;
		while(temp){
			if(temp % 2) sum += a[mid + j];
			temp >>= 1;
			j++;
		}
		if(sum == S) ans++;
		v[1].push_back(sum);
	}
	sort(v[1].begin(), v[1].end());
	for(int i = 0; i < v[0].size(); i++){
		auto st = lower_bound(v[1].begin(), v[1].end(), S - v[0][i]);
		if(st == v[1].end() || *st != S-v[0][i]) continue;
		auto ed = upper_bound(v[1].begin(), v[1].end(), S - v[0][i]);
		ans += ed - st;
	}
	cout << ans << "\n";
    return 0;
}