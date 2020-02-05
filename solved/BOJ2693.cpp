#include <bits/stdc++.h>

using namespace std;

int T, arr[10];

int main(){
    scanf("%d", &T);
    while(T--){
        for(int i = 0; i < 10; i++)
            scanf("%d", arr + i);
        sort(arr, arr + 10);
        printf("%d\n", arr[7]);
    }
    return 0;
}