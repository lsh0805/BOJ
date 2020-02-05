#include <stdio.h>
#include <algorithm>

using namespace std;

int N, curr, st, p, ans;

int main(){
    scanf("%d", &N);
    scanf("%d", &st);    
    for(int i = 1; i < N; i++){
        scanf("%d", &curr);
        if(p < curr)
            ans = max(ans, curr - st);
        else{
            st = curr;
        }
        p = curr;
    }
    printf("%d", ans);
    return 0;
}