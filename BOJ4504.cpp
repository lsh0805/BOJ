#include <stdio.h>

int n, num;

int main(){
    scanf("%d", &n);
    while(true){
        scanf("%d", &num);
        if(num == 0) return 0;
        if(num % n == 0){
            printf("%d is a multiple of %d.\n", num, n);
        }else{
            printf("%d is NOT a multiple of %d.\n", num, n);
        }
    }
    return 0;
}