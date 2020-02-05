#include <stdio.h>

int a[2], num;

int main(){
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 4; j++){
            scanf("%d", &num);
            a[i] += num;
        }
    printf("%d", a[0] > a[1] ? a[0] : a[1]);
}