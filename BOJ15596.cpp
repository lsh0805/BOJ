#include <stdio.h>

int n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2; j++){
            if(j%2 != i%2)
                putchar(' ');
            else
                putchar('*');
        }
        putchar('\n');
    }
    return 0;
}j