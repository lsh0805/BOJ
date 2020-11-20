#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, n, m, A[1001], B[1001], a_sum[1001], b_sum[1001];
ll ans;
vector<int> a_seg, b_seg;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        if(i > 0)
            a_sum[i] = A[i] + a_sum[i - 1];
        else
            a_sum[i] = A[i];
        a_seg.push_back(a_sum[i]);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> B[i];
        if(i > 0)
            b_sum[i] = B[i] + b_sum[i - 1];
        else
            b_sum[i] = B[i];
        b_seg.push_back(b_sum[i]);
    }
    for(int i = 1; i < m; i++)
        for(int j = i; j < m; j++)
            b_seg.push_back(b_sum[j] - b_sum[i - 1]);
    sort(b_seg.begin(), b_seg.end());
    for(int i = 1; i < n; i++)
        for(int j = i; j < n; j++)
            a_seg.push_back(a_sum[j] - a_sum[i - 1]);
    for(int i = 0; i < a_seg.size(); i++){
        auto it = lower_bound(b_seg.begin(), b_seg.end(), T - a_seg[i]);
        if(it == b_seg.end() || *it != T - a_seg[i]) continue;
        ans += upper_bound(b_seg.begin(), b_seg.end(), T - a_seg[i]) - it;
    }
    cout << ans;
}