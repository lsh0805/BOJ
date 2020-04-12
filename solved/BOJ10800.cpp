#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, c[200001], s[200001], p_sum[200001];
vector<int> v, c_v[200001], c_p_sum[200001];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> c[i] >> s[i];
        c[i]--;
        v.push_back(s[i]);
        c_v[c[i]].push_back(s[i]);
    }
    sort(v.begin(), v.end());
    p_sum[0] = v[0];
    for(int i = 1; i < N; i++)
        p_sum[i] = p_sum[i - 1] + v[i];
    for(int i = 0; i < N; i++){
        if(c_v[i].size() == 0) continue;
        sort(c_v[i].begin(), c_v[i].end());
        c_p_sum[i].push_back(c_v[i][0]);
        for(int j = 1; j < c_v[i].size(); j++)
            c_p_sum[i].push_back(c_p_sum[i][j - 1] + c_v[i][j]);
    }
    for(int i = 0; i < N; i++){
        int color = c[i];
        int idx = lower_bound(v.begin(), v.end(), s[i]) - v.begin();
        int sum = 0;
        if(idx > 0)
            sum = p_sum[idx - 1];
        idx = lower_bound(c_v[color].begin(), c_v[color].end(), s[i]) - c_v[color].begin();
        int sub = 0;
        if(idx > 0)
            sub = c_p_sum[color][idx - 1];
        cout << sum - sub << '\n';
    }
    return 0;
}