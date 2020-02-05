#include <bits/stdc++.h>

using namespace std;

const int MOD = 1234567891;
int L;
long long ans;

long long cal(int num, int x){
    long long r = 1;
    for(int i = 0; i < x; i++)
        r = (r * 31) % MOD;
    r = r * (long long)num;
    return (r % MOD);
}

int main(){
    scanf("%d", &L);
    getchar();
    for(int i = 0; i < L; i++){
        long long num = cal(getchar() - 'a' + 1, i);
        ans = (ans + num) % MOD;
    }
    printf("%lld", ans);
}
