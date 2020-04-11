#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int T, N, ans, a[40001];
vector<int> v;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> a[0];
    v.push_back(a[0]);
    for(int i = 1; i < N; i++){
        cin >> a[i];
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if(it == v.end()){
            v.push_back(a[i]);
        }else{
            *it = a[i];
        }
    }
    cout << v.size();
    return 0;
}