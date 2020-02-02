#include <stdio.h>
#include <vector>

using namespace std;
int T;
bool notPrime[2000001];
long long A, B, sum;
vector<int> prime;

int main(){
    scanf("%d", &T);
    for(int i = 3; i * i <= 2000000; i+=2){
        if(notPrime[i]) continue;
        for(int j = i * i; j <= 2000000; j += i)
            notPrime[j] = true;
    }
    for(int i = 3; i < 2000000; i+=2)
        if(!notPrime[i]) 
            prime.push_back(i);
    while(T--){
        scanf("%lld %lld", &A, &B);
        sum = A + B;
        if(sum < 4){
            printf("NO\n");
            continue;
        }
        if(sum % 2 == 0){
            printf("YES\n");
            continue;
        }
        sum -= 2;
        bool flag = false;
        for(int i = 0; i < prime.size() && (long long)prime[i] * prime[i] <= sum; i++){
            if(sum % prime[i] == 0){
                flag = true;
                break;
            }
        }
        printf(flag ? "NO\n" : "YES\n");
    }
    return 0;
}