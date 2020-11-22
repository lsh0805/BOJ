#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int N, ans;
bool isPrime[4000001];
vector<int> primes;
deque<int> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i <= N; i += 2)
        isPrime[i] = false;
    primes.push_back(2);
    for(int i = 3; i <= N; i++){
        if(isPrime[i])
            primes.push_back(i);
        if(i >= 7000) continue;
        for(int j = i * i; j <= N; j+=i)
            isPrime[j] = false;
    }
    int curr = 0;
    for(int i = 0; i < primes.size(); i++){
        curr += primes[i];
        q.push_back(primes[i]);
        for(int i = 0; curr > N; i++){
            curr -= q.front();
            q.pop_front();
        }
        if(curr == N)
            ans++;
    }
    cout << ans;
    return 0;
}