#include <bits/stdc++.h>

using namespace std;

int N, num, arr[2000002];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        arr[num+1000000] = 1;
    }
    for(int i = 1000000; i >= -1000000; i--)
        if(arr[i+1000000])
         
            printf("%d\n", i);
    return 0;
}