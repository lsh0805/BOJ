#include <stdio.h>
#include <set>

using namespace std;

int N, num, arr[2200];
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        arr[num + 1000] = 1;
    }
    for(int i = 0; i < 2200; i++){
        if(arr[i] == 1)
            printf("%d ", i - 1000);
    }
    return 0;
}