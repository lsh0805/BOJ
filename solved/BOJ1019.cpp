#include <bits/stdc++.h>

using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define FOR(x, i, n) for(int x = i; x < n; x++)
#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

ll N, cnt[10], f[10], b[10];
vector<int> v;


int pow(int c){
	if(c < 0) return 0;
	int ret = 1;
	for(int i = 0; i < c; i++)
		ret *= 10;
	return ret;
}

int main(){
    IO;
	cin >> N;
	for(int i = 0; N != 0; i++){
		v.push_back(N % 10);
		N /=10;
	}
	reverse(v.begin(), v.end());
	int mul = 1;
	for(int i = v.size() - 2; i >= 0; i--){
		b[i] = b[i + 1] + v[i + 1] * mul;
		mul *= 10;
	}
	for(int i = 1; i < v.size(); i++){
		f[i] = f[i - 1] * 10 + v[i - 1];
	}
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < 10; j++){
			if(!(j == 0 && i == 0) && v[i] == j)
				cnt[j] += b[i] + 1;
			else if(v[i] > j)
				cnt[j] += pow(v.size() - 1 - i);
			cnt[j] += f[i] * pow(v.size() - 1 - i);
			if(j == 0)
				cnt[j] -= pow(v.size() - 1 - i);
		}
	}
	for(int i = 0; i < 10; i++)
		cout << cnt[i] << " ";
    return 0;
}