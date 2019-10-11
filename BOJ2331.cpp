#include <stdio.h>
#include <map>

using namespace std;

int used[10000000];
int A, P, curr;

int power(int num){
    int ret = 0;
    while(num){
        int n = num % 10;
        int add = n;
        for(int i = 1; i < P; i++)
            add *= n;
        ret += add;
        num /= 10;
    }
    return ret;
}

int main(){
    scanf("%d %d", &A, &P);
    used[A] = 1;
    int i = 2;
    while(true){
        curr = power(A);
        if(used[curr] > 0){
            printf("%d\n", used[curr] - 1);
            break;
        }
        used[curr] = i++;
        A = curr;
    }
    return 0;
}