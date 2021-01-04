#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> P2;

int T, N;
vector<P2> v;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        int ans = N;
        v = vector<P2>(N);
        for(int i = 0; i < N; i++){
            cin >> v[i].x.x >> v[i].x.y;
        }
        sort(v.begin(), v.end());
        int min_ = v[0].x.y;
        for(int i = 1; i < N; i++){
            if(min_ < v[i].x.y)
                ans--;
            min_ = min(min_, v[i].x.y);
        }
        cout << ans << "\n";
    }
}