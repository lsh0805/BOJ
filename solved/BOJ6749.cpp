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
typedef pair<int, int> pii;

int Y, M;

int main()
{
    IO;
    cin >> Y >> M;
    cout << M + (M - Y) << endl;
    return 0;
}