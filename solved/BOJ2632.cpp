#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int A, B, C, a[1001], b[1001], a_sum, b_sum, sum;
map<int, int> m;
ll ans;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> C >> A >> B;
    for(int i = 0; i < A; i++){
        cin >> a[i];
        a_sum += a[i];
    }
    m[0]++;
    m[a_sum]++;
    for (int i = 0; i < A; i++)
    {
        sum = 0;
        for (int j = 0; j < A - 1; j++)
        {
            if (i + j >= A)
                sum += a[i + j - A];
            else
                sum += a[i + j];
            m[sum]++;
        }
    }
    for(int i = 0; i < B; i++){
        cin >> b[i];
        b_sum += b[i];
    }
    for (int i = 0; i < B; i++)
    {
        sum = 0;
        for (int j = 0; j < B - 1; j++)
        {
            if (i + j >= B)
                sum += b[i + j - B];
            else
                sum += b[i + j];
            ans += m[C - sum];
        }
    }
    cout << ans + m[C - b_sum] + m[C];
    return 0;
}