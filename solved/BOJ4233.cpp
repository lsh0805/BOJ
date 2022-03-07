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

int a, p;

int pow(int num, int x) {
    if (x == 1) return num;
    if (x == 0) return 1;
    ll mul = (pow(num, x / 2) % p);
    if (x % 2) {
        return ((mul * mul) % p * num) % p;
    } else {
        return (mul * mul) % p;
    }
}

int main()
{
    IO;
    while(true) {
        cin >> p >> a;
        if (a == 0 && p == 0) break;
        bool isPrime = true;
        if (p % 2 == 0) {
            isPrime = false;
        } else {
            for (int i = 3; i <= sqrt(p); i+=2) {
                if (p % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            cout << "no\n";
        } else {
            int res = pow(a, p);
            if (res == a) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
    return 0;
}