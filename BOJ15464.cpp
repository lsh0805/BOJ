#include <stdio.h>

using namespace std;

int N, a[101], id[101], num;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        a[num - 1] = i;
    }
    for(int i = 0; i < N; i++)
        scanf("%d", &id[i]);
    for(int i = 0; i < 3; i++){
        int temp[101] = {0,};
        for(int j = 0; j < N; j++)
            temp[a[j]] = id[j];
        for(int j = 0; j < N; j++)
            id[j] = temp[j];
    }
    for(int i = 0; i < N; i++)
        printf("%d\n", id[i]);
    return 0;
}