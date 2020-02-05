#include <stdio.h>

int T, a, b, s1, s2;

int main(){
    scanf("%d", &T);
    while(T--){
        for(int i = 0; i < 9; i++){
            scanf("%d %d", &a, &b);
            s1 += a;
            s2 += b;
        }
        if(s1 < s2){
            printf("Korea\n");
        }else if(s1 > s2){
            printf("Yonsei\n");
        }else{
            printf("Draw\n");
        }
        s1 = 0;
        s2 = 0;
    }
    return 0;
}