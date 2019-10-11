#include <stdio.h>

int arr[6] = {1, 1, 2, 2, 2, 8}, num;

int main(){
    for(int i = 0; i < 6; i++){
        scanf("%d", &num);
        printf("%d ", arr[i] - num);
    }
    return 0;
}