#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
typedef pair<int, int> ii;

string str;
char c;
int cnt[2];

int main()
{
    IO;
    cin >> str;
    c = str[0];
    cnt[c - '0']++;
    int i = 0;
    for (; i < str.length(); i++)
    {
        if (str[i] != c)
        {
            c = str[i];
            cnt[c - '0']++;
        }
    }
    cout << min(cnt[0], cnt[1]) << endl;
    return 0;
}