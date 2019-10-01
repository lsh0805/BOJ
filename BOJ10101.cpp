#include <stdio.h>

int a, b, c;

int main(){
    scanf("%d %d %d", &a, &b, &c);
    if(a == 60 && b == 60 && c == 60){
        printf("Equilateral");
    }else if(a + b + c == 180){
        if(a == b || a == c || b == c){
            printf("Isosceles");
        }else{
            printf("Scalene");
        }
    }else{
        printf("Error");
    }
    return 0;
}