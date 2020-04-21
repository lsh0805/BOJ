#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

ll K, N, a[101];
set<ll> s;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> K >> N;
    for(int i = 0; i < K; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    auto it = s.begin();
    for(int i = 0; i < N - 1; it++, i++){
        ll curr = *it;
        for(int j = 0; j < K; j++){
            if(a[j] * curr <= INT32_MAX)
                s.insert(a[j] * curr);
        }
        while(s.size() > N)
            s.erase(prev(s.end()));
    }
    cout << *it;
    return 0;
}