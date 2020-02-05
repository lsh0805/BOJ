#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
int a[3], b;

int main(){
    while(true){
        scanf("%d %d %d", a, a + 1, a + 2);
        sort(a, a+3);
        if(a[2] == 0)
            break;
        
        printf((a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) ? "right\n" : "wrong\n");
    }
    return 0;
}