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

int N, a[101];
vector<int> v;

bool t(int x) {
    int r = -1;
    for (int i = 0; i < N; i++) {
        if (r == -1) {
            r = a[i] % x;
        } else if(r != a[i] % x) {
            return false;
        }
    }
    return true;
}

void p(int x, int y) {
    int diff = abs(x -  y);
    for(int i = 1; i * i <= diff; i++) {
        if (i * i == diff) {
            if (t(i)) v.push_back(i);
        } else if (diff % i == 0) {
            if (t(i)) v.push_back(i);
            if (t(diff / i)) v.push_back(diff/i);
        }
    }
}

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    p(a[0], a[1]);
    sort(v.begin(), v.end());
    for (int i = 0; i <v.size(); i++) {
        if (v[i] != 1)
        cout << v[i] << " ";
    }
    return 0;
}