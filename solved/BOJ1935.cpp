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

vector<double> v;
int N, c[30];
string s;

int main()
{
    IO;
    cin >> N >> s;
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < s.size(); i++)
    {
        double a, b;
        if (s[i] < 'A' || s[i] > 'Z')
        {
            b = v.back();
            v.pop_back();
            a = v.back();
            v.pop_back();
        }
        switch (s[i])
        {
        case '*':
            v.push_back(a * b);
            break;
        case '+':
            v.push_back(a + b);
            break;
        case '/':
            v.push_back(a / b);
            break;
        case '-':
            v.push_back(a - b);
            break;
        default:
            v.push_back(c[s[i] - 'A']);
            break;
        }
    }
    cout.precision(2);
    cout << fixed << v[0];
    return 0;
}