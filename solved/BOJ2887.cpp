#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;


int N, p[100001], r[100001], cnt, ans;
P x[100001], y[100001], z[100001];
vector<P2> v;

int find(int curr){
    if(curr == p[curr]) return curr;
    return p[curr] = find(p[curr]);
}

bool merge(int u, int v){
    u = find(u), v = find(v);
    if(r[u] < r[v])
        swap(u, v);
    if(p[u] == p[v]) return false;
    p[v] = u;
    if(r[u] == r[v])
        r[u]++;
    return true;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        p[i] = i;
        int x_, y_, z_;
        cin >> x_ >> y_ >> z_;
        x[i] = P(x_, i);
        y[i] = P(y_, i);
        z[i] = P(z_, i);
    }
    sort(x, x + N);
    sort(y, y + N);
    sort(z, z + N);
    for(int i = 1; i < N; i++){
        v.push_back(P2(x[i].fi - x[i - 1].fi, P(x[i].se, x[i - 1].se)));
        v.push_back(P2(y[i].fi - y[i - 1].fi, P(y[i].se, y[i - 1].se)));
        v.push_back(P2(z[i].fi - z[i - 1].fi, P(z[i].se, z[i - 1].se)));
    }
    sort(v.begin(), v.end());
    for(int i = 0, cnt = 0; cnt == N || i < v.size(); i++){
        int x = v[i].se.fi, y = v[i].se.se;
        if(merge(x, y)){
            ans += v[i].fi;
            cnt++;
        }
    }
    cout << ans << "\n";
}