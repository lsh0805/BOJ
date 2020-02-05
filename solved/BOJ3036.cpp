#include <stdio.h>
#include <algorithm>

using namespace std;
int N, a, b;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    scanf("%d", &N);
    scanf("%d", &a);
    for(int i = 1; i < N; i++){
        scanf("%d", &b);
        int d = gcd(a, b);
        printf("%d/%d\n", a / d, b / d);
    }
}