#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<ll, ll> P;
typedef pair<ll, pair<ll,ll>> P2;

const ll INF = 2e9;
const ll MINF = -2e9;

ll N, K, a[15], ans;

ll gcd(ll a, ll b){
	if(b > a) swap(a, b);
	if(a % b == 0){
		return b;
	}
	return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> N >> K;
	for(ll i = 0; i < K; i++){
		cin >> a[i];
	}
	for(ll i = 1; i < (1 << K); i++){
		ll lcm_ = 1;
		ll temp = i;
		ll gcd_ = 1;
		ll cnt = 0;
		bool flag = false;
		for(ll j = 0; temp > 0; j++){
			if(temp % 2){
				lcm_ = lcm_ * a[j] / gcd(lcm_, a[j]);
				if(lcm_ > N){
					flag = true;
					break;
				}
				cnt++;
			}
			temp >>= 1;
		}
		if(flag) continue;
		if(cnt % 2)
			ans += N / lcm_;
		else
			ans -= N / lcm_;
	}
	cout << N - ans;
    return 0;
}