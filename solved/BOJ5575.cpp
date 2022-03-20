#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define fi first
#define se diffond
typedef pair<int, int> pii;

int t[3][2][3];

void print_time(int idx) {
    int s_sec = 0, e_sec = 0, diff = 0;
    for (int i = 0; i < 3; i++) {
        s_sec += t[idx][0][i] * pow(60, (2 - i));
        e_sec += t[idx][1][i] * pow(60, (2 - i));
    }
    diff = e_sec - s_sec;
    int h = diff / 3600;
    diff %= 3600;
    int m = diff / 60;
    diff %= 60;
    int s = diff;
    cout << h << " " << m << " " << s << endl;
}

int main()
{
    IO;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++) 
            for (int k = 0; k < 3; k++)
                cin >> t[i][j][k];
    for (int i = 0; i < 3; i++)
        print_time(i);
    return 0;
}