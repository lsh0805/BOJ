#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const ll INF = 2e10;
const int MINF = -2e9;

ll N, num, ans[3] = {0, 1, 2}, min_;
vector<ll> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	min_ = INF;
	sort(v.begin(), v.end());
	ans[0] = v[0];
	ans[1] = v[1];
	ans[2] = v[2];
	for(int i = 0; i < N - 2; i++)
		for(int j = i + 1; j < N - 1; j++)
		{
			ll sum = v[i] + v[j];
			auto it = lower_bound(v.begin() + j + 1, v.end(), -sum);
			if(it == v.end()){
				int idx = v.size() - 1;
				if(abs(v[idx] + sum) < min_){
					min_ = abs(v[idx] + sum);
					ans[0] = v[i]; ans[1] = v[j]; ans[2] = v[idx];
				}
			}
			else{
				int idx = it - v.begin();
				if(abs(v[idx] + sum) < min_){
					min_ = abs(v[idx] + sum);
					ans[0] = v[i]; ans[1] = v[j]; ans[2] = v[idx];
				}
				if(idx - 1 > j && abs(v[idx - 1] + sum) < min_){
					min_ = abs(v[idx - 1] + sum);
					ans[0] = v[i]; ans[1] = v[j]; ans[2] = v[idx - 1];
				}
			}
		}
	cout << ans[0] << " "<< ans[1] << " " << ans[2];
    return 0;
}