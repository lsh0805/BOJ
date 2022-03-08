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

int T;
double val;
char op;
string str;

int main()
{
    IO;
    getline(cin, str);
    T = stoi(str);
    while(T--) {
        getline(cin, str);
        stringstream ss;
        ss << str;
        ss >> val;
        while(ss >> op && !ss.eof()) {
            switch (op)
            {
            case '@':
                val *= 3;
                break;
            case '%':
                val += 5;
                break;
            case '#':
                val -= 7;
                break;
            default:
                break;
            }
        }
        cout << fixed << setprecision(2) << val << endl;
    }
    return 0;
}