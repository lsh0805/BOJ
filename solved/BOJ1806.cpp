#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int N, S, a[100001], p_sum[100001], s = 1, e = 1;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        p_sum[i] = p_sum[i - 1] + a[i];
    }
    int ans = 2e9;
    while(s <= N && e <= N){
        int val = p_sum[e] - p_sum[s - 1];
        if(val < S){
            e++;
        }else if(val >= S){
            ans = min(ans, e - s + 1);
            if(s < e)
                s++;
            else
                break;
        }
    }
    if(ans == 2e9)
        cout << 0;
    else
        cout << ans;
    return 0;
}