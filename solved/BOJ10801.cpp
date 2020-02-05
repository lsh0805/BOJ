#include <stdio.h>

int a[10], b[10], cnt_a, cnt_b;

int main(){
    for(int i = 0; i < 10; i++)
        scanf("%d", a+ i);
    for(int i = 0; i < 10; i++)
        scanf("%d", b+ i);
    for(int i = 0; i < 10; i++){
        cnt_a += a[i] > b[i];
        cnt_b += a[i] < b[i];
    }
    if(cnt_a > cnt_b){
        putchar('A');
    }else if(cnt_a < cnt_b){
        putchar('B');
    }else{
        putchar('D');
    }
    return 0;
}