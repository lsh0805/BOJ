#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
typedef pair<int, int> ii;

ll A, B;
int ans;
set<ll> visited;
queue<ll> q;

int main()
{
    IO;
    cin >> A >> B;
    q.push(A);
    visited.insert(A);

    ll MAX = min((ll)1e9, B);

    while (!q.empty())
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            ll curr = q.front();
            if (curr == B)
            {
                cout << ans + 1 << endl;
                return 0;
            }
            q.pop();
            ll next = curr * 2;
            if (next <= MAX && visited.find(next) == visited.end())
            {
                q.push(next);
                visited.insert(next);
            }
            next = curr * 10 + 1;
            if (next <= MAX && visited.find(next) == visited.end())
            {
                q.push(next);
                visited.insert(next);
            }
        }
        ans++;
    }
    cout << -1 << endl;
    return 0;
}