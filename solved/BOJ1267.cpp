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

int N, a, Y, M;

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        Y += ((a / 30) * 10) + 10;
        M += ((a / 60) * 15) + 15;
    }
    if (Y > M)
        cout << "M " << M;
    else if(Y < M)
        cout << "Y " << Y;
    else
        cout << "Y M " << Y;
    return 0;
}