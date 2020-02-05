#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5;
int N, arr[MAX_N + 1], num, cnt;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        if(arr[cnt] < num){
            arr[++cnt] = num;
        }else{
            int *it = lower_bound(arr, arr + cnt + 1, num);
            *it = num;
        }
    }
    printf("%d", N - cnt);
    return 0;
}