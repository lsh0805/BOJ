#include <stdio.h>
#include <algorithm>

using namespace std;
int T;
int main(){
    scanf("%d", &T);
    while(T--){
        int arr[4] = {0, }, num;
        for(int i = 0; i < 8; i++){
            scanf("%d", &num);
            arr[i % 4] += num;
        }
        arr[0] = max(1, arr[0]);
        arr[1] = max(1, arr[1]);
        arr[2] = max(0, arr[2]);
        printf("%d\n", arr[0] * 1 + arr[1] * 5 + arr[2] * 2 + arr[3] * 2);
    }
    return 0;
}