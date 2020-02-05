#include <bits/stdc++.h>

using namespace std;

int A, B, N, num, d;
stack<int> ans;
int main(){
    scanf("%d %d %d", &A, &B, &N);
    for(int i = N - 1; i >= 0; i--){
        scanf("%d", &num);
        d += num*pow(A, i);
    }
    while(d > 0){
        ans.push(d % B);
        d /= B;
    }
    while(ans.size() > 0){
        printf("%d ", ans.top());
        ans.pop();
    }
}