#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9 + 7;
const int MINF = -2e9;

int N, min_, ans[2];
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> N;
	v = vector<int>(N);
	for(int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	min_ = INF;
	for(int i = 0; i < N - 1; i++)
	{
		auto it = lower_bound(v.begin() + i + 1, v.end(), -v[i]);
		int idx = it - v.begin();
		if(idx == v.size()){
			if(abs(v[i] + v[v.size() - 1]) < min_){
				min_ = abs(v[i] + v[v.size() - 1]);
				ans[0] = v[i];
				ans[1] = v[v.size() - 1];
			}
		}
		else{
			if(abs(v[i] + v[idx]) < min_){
				min_ = abs(v[i] + v[idx]);
				ans[0] = v[i];
				ans[1] = v[idx];
			}
			if(idx - 1 > i && abs(v[i] + v[idx - 1]) < min_){
				min_ = abs(v[i] + v[idx - 1]);
				ans[0] = v[i];
				ans[1] = v[idx - 1];
			}
		}
	}
	cout << ans[0] << " " << ans[1];
    return 0;
}