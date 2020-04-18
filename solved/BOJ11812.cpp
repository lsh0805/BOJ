#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

ll N, K, Q, x, y;

ll p(ll num, ll x){
    if(x == 0)
        return (ll) 1;
    if(x == 1)
        return (ll) num;
    ll half = p(num, x / 2);
    if(x % 2)
        return half * half * num;
    else
        return half * half;
}

ll dist(ll u, ll v){
    if(K == 1)
        return abs(u - v);
    ll left = 0, right = 0;
    ll d_u = 0, d_v = 0;
    for(ll d = 0; right < N; d++){
        left = right + 1;
        right = left + p(K, d) - 1;
        if(u >= left && u <= right)
            d_u = d;
        if(v >= left && v <= right)
            d_v = d;
    }
    if(d_u < d_v){
        swap(d_u, d_v);
        swap(u, v);
    }
    ll diff = d_u - d_v;
    for(int i = 0; i < diff; i++){
        u = (u + (K - 2)) / K;
        d_u--;
    }
    ll ret = diff;
    if(u == v){
        return ret;
    }else{
        while(u != v){
            u = (u + (K - 2)) / K;
            v = (v + (K - 2)) / K;
            ret += 2;
        }
        return ret;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K >> Q;
    while(Q--){
        cin >> x >> y;
        cout << dist(x, y) << "\n";
    }
    return 0;
}