#include <stdio.h>
#include <algorithm>

using namespace std;

int N, ans, num[3];
int main(){
    scanf("%d", &N);
    while(N--){
        scanf("%d %d %d", &num[0], &num[1], &num[2]);
        sort(num, num + 3);
        int curr = 0;
        if(num[0] == num[2])
            ans = max(ans, 10000 + num[0] * 1000);
        else if(num[0] == num[1] || num[1] == num[2])
            ans = max(ans, 1000 + num[1] * 100);
        else
            ans = max(ans, num[2] * 100);
    }
    printf("%d", ans);
    return 0;
}