#include <stdio.h>

char c;
int main(){
    while((c = getchar()) != EOF){
        if(c == 'C' || c == 'A' || c == 'M' || c == 'B' || c == 'R' || c == 'I' || c == 'D' || c == 'G' || c == 'E')
            continue;
        putchar(c);
    }

    return 0;
}