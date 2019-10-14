#include <stdio.h>

int T, sum, num, min = 1e9;

int main(){
    scanf("%d", &T);
    while(T--){
        sum = 0;
        min = 1e9;
        for(int i = 0; i < 7; i++){
            scanf("%d", &num);
            if(num % 2 == 0){
                sum += num;
                if(min > num)
                    min = num;
            }
        }
        printf("%d %d\n", sum, min);
    }
    return 0;
}