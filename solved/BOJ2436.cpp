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

int T, N;
ll a, b, mul, ans[2];


ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b;
    mul = a * b;
    ans[0]=a;
    ans[1]=b;
    for(ll i = a; i <= sqrt(mul); i+=a){
        if(mul % i == 0 && gcd(i, mul / i) == a){
            if(i + (mul / i) < ans[0] + ans[1]){
                ans[0] = i;
                ans[1] = mul/i;
            }
        }
    }
    cout << ans[0] << " " << ans[1];
    return 0;
}