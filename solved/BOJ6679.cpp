#include <stdio.h>

int parse(int i, int val){
    int res = 0;
    while(i){
        res += i % val;
        i /= val;
    }
    return res;
}

bool check(int i){
    int a = parse(i, 12);
    int b = parse(i, 10);
    int c = parse(i, 16);
    return a == b && a == c && c == b;
}

int main(){
    for(int i = 1000; i <= 9999; i++){
        if(check(i))
            printf("%d\n", i);
    }
    return 0;
}