#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, arr[4][4001];
long long ans;
vector<int> v;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int j = 0; j < N; j++)
        for(int i = 0; i < 4; i++)
            cin >> arr[i][j];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            v.push_back(arr[0][i] + arr[1][j]);
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            int oppo = -(arr[2][i] + arr[3][j]);
            auto it = lower_bound(v.begin(), v.end(), oppo);
            if(it == v.end()) continue;
            if(*it == oppo)
                ans += upper_bound(v.begin(), v.end(), oppo) - it;
        }
    cout << ans;
    return 0;
}