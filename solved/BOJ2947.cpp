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

int a[5];

void print() {
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    IO;
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                print();
            }
        }
    }
    return 0;
}