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

int N, M, K;

int main()
{
    IO;
    cin >> N >> M >> K;
    cout << K / M << " " << K % M; 
    return 0;
}