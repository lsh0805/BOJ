#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N;
ll a[1001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a+N);
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        if(ans + 1 < a[i])
            break;
        ans += a[i];
    }
    cout << ans + 1 << '\n';
    return 0;
}