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

int N, M, cvt[10001], cvt2[10001];
vector<int> v, v2;
set<int> s;

void print(int val)
{
    if (val >= 10)
        print(val / 10);
    cout << cvt2[val % 10] << " ";
}

void f(int cal, int curr)
{
    if (cal >= pow(10, M))
    {
        return;
    }

    if (cal >= pow(10, M - 1))
    {
        if (s.find(cal) == s.end())
        {
            s.insert(cal);
            print(cal);
            cout << endl;
        }
    }
    for (int i = curr + 1; i < v2.size(); i++)
    {
        f(cal * 10 + v2[i], i);
    }
}

int main()
{
    IO;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int j = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (cvt[v[i]] == 0)
        {
            cvt[v[i]] = j;
            j++;
        }
        cvt2[cvt[v[i]]] = v[i];
        v2.push_back(cvt[v[i]]);
    }
    for (int i = 0; i < N; i++)
    {
        f(v2[i], i);
    }
    return 0;
}