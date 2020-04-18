#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, a[101], total = 1, ans = 1, cnt, prime_cnt[1000001];

int power(int num, int x){
    int ret = 1;
    for(int i = 0; i < x; i++)
        ret *= num;
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        int temp = a[i];
        for(int j = 2; temp > 1; j++){
            int p = 0;
            while(temp % j == 0){
                temp /= j;
                p++;
            }
            prime_cnt[j] += p;
        }
    }
    for(int i = 2; i <= 1000000; i++)
        ans *= pow(i, prime_cnt[i] / N);
    for(int i = 0; i < N; i++){
        for(int j = 2; j <= 1000000; j++){
            int p = 0;
            while(a[i] % j == 0){
                a[i] /= j;
                p++;
            }
            if(prime_cnt[j] / N > p)
                cnt += (prime_cnt[j] / N) - p;
        }
    }
    cout << ans << " " << cnt;
    return 0;
}