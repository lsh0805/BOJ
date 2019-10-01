#include <stdio.h>
#include <math.h>

int N;

int power(int p){
    int res = 1;
    while(p){
        res *= 10;
        p--;
    }
    return res;
}

long long solve(){
    long long ans = 0, curr = 0, next, p = 1;
    while(true){
        next = power(p) - 1;
        if(next >= N) break;
        ans += (next - curr) * p;
        curr = next;
        p++;
    }
    return ans += (N - curr) * (p);
}

int main(){
    scanf("%d", &N);
    printf("%lld", solve());
    return 0;
}