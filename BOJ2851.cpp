#include <stdio.h>
#include <math.h>

int sum, num;

int main(){
    for(int i = 0; i < 10; i++){
        scanf("%d", &num);
        if(abs(sum - 100) < abs(sum + num - 100))
            break;
        sum += num;
    }
    printf("%d", sum);
    return 0;
}