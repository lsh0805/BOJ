#include <stdio.h>
#include <math.h>

int T, s, d, ans;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &s, &d);
        long long dist = d - s;
        long long root = (long long)sqrt(dist);
        ans = root * 2 - 1;
        if(!(root * root == dist)){
            ans++;
            if(dist > (root*root+root)){
                ans++;
            }
        }
        if(dist <= 3)
            ans = dist;
        printf("%d\n", ans);
    }
    
    return 0;
}