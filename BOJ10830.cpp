#include <stdio.h>
#include <vector>

using namespace std;

int N;
long long B;
typedef vector<vector<int>> Matrix;

Matrix A, ans;


Matrix operator * (const Matrix & a, const Matrix & b){
    Matrix ret(N, vector<int>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++){
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= 1000;
            }
    return ret;
}

int main(){
    scanf("%d %lld", &N, &B);
    A = Matrix(N, vector<int>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            scanf("%d", &A[i][j]);
            A[i][j] %= 1000;
        }
    B--;
    ans = A;
    while(B){
        if(B % 2 == 1)
            ans = ans * A;
        A = A * A;
        B /= 2;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}