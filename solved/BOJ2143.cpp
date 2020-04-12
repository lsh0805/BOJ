#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
map<ll, ll> m;
ll T, N, M, a[1001], b[1001], a_sum, b_sum, ans;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    for(int i = 0; i < N; i++){
        a_sum = 0;
        for(int j = i; j < N; j++){
            a_sum += a[j];
            m[a_sum]++;
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> b[i];
    
    for(int i = 0; i < M; i++){
        b_sum = 0;
        for(int j = i; j < M; j++){
            b_sum += b[j];
            ans += m[T - b_sum];
        }
    }
    cout << ans << '\n';
    return 0;
}