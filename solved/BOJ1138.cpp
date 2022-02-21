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

int N, a[10];
priority_queue<int> pq;
int main()
{
    IO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] == 0)
            pq.push(-i);
    }
    while(!pq.empty()) {
        int top = -pq.top();
        pq.pop();
        cout << top + 1 << " ";
        for (int i = 0; i < top; i++) {
            a[i]--;
            if (a[i] == 0)
                pq.push(-i);
        }
    }
    cout << "\n";
    return 0;
}