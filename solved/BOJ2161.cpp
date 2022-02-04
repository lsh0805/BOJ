#include <bits/stdc++.h>

using namespace std;

#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define LL long long
#define endl "\n"

typedef pair<int, int> ii;

int N;

deque<int> dq;

int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        dq.push_back(i + 1);
    }
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
        if (!dq.empty())
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    return 0;
}