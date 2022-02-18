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

int N;
string str;
vector<string> v;

bool comp(string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    else {
        int a_sum = 0, b_sum = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] >= '0' && a[i] <= '9') {
                a_sum += a[i] - '0';
            }
            if (b[i] >= '0' && b[i] <= '9') {
                b_sum += b[i] - '0';
            }
        }
        if (a_sum != b_sum)
            return a_sum < b_sum;
    }
    return a.compare(b) < 0;
}

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}