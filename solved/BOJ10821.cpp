#include <stdio.h>

char c;
int ans = 0;
int main(){
    while((c = getchar()) != EOF)
        ans += c == ',';
    ans++;
    printf("%d", ans);
    return 0;
}