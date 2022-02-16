#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define fi first
#define se second
typedef pair<int, int> ii;

int N, min_ = 1001, max_, num;

int main()
{
    IO;
    cin >> N;
    while(N--) {
        cin >> num;
        min_ = min(min_, num);
        max_ = max(max_, num);
    }
    cout << max_ - min_;

    return 0;
}