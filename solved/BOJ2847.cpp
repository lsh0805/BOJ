#include <stdio.h>

int N, arr[101], ans;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    for(int i = N - 1; i > 0; i--)
        if(arr[i] <= arr[i - 1]){
            ans += arr[i - 1] - (arr[i] - 1);
            arr[i - 1] = arr[i] - 1;
        }
    printf("%d", ans);
    return 0;
}