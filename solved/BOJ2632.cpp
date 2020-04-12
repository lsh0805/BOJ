#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int A, B, C, a[1001], b[1001], c[2000001], a_sum, b_sum, sum;
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
    c[0]++;
    c[a_sum]++;
    for (int i = 0; i < A; i++)
    {
        sum = 0;
        for (int j = 0; j < A - 1; j++)
        {
            if (i + j >= A)
                sum += a[i + j - A];
            else
                sum += a[i + j];
            c[sum]++;
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
            if(C - sum >= 0)
            ans += c[C - sum];
        }
    }
    if(C - b_sum >= 0)
        ans += c[C - b_sum];
    cout << ans + c[C];
    return 0;
}