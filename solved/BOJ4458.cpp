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

int N;
char c;
string str;

int main()
{
    IO;
    cin >> N;
    cin.ignore();
    while(N--) {
        getline(cin, str);
        str[0] = toupper(str[0]);
        cout << str << endl;
    }
    return 0;
}