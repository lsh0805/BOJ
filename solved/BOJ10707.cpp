#include <stdio.h>

int A, B, C, D, P, X, Y;

int main(){
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &P);
    X = P * A;
    Y = B;
    if(P > C)
        Y += (P - C) * D;
    printf("%d", X > Y ? Y : X);
    return 0;
}