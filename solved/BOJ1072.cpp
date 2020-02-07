#include <bits/stdc++.h>

using namespace std;

long long X, Y, Z;

int main(){
    scanf("%lld %lld", &X, &Y);
    Z = Y * 100/X;
    if(Z >= 99){
        printf("-1");
        return 0;
    }
    long long left = 0, right = 1e9 + 1;
    while(left + 1 < right){
        long long mid = (left + right) / 2;
        if(Z == (Y+mid)*100/(X+mid))
            left = mid;
        else
            right = mid;
    }
    printf("%lld", right);
    return 0;
}