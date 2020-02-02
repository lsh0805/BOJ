#include <bits/stdc++.h>

using namespace std;

int N, tree[100001], diff[100001];
long long diff_sum;

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", tree + i);
        if(i > 0)
            diff[i] = tree[i] - tree[i - 1];
        diff_sum += diff[i];
    }
    int prev_gcd = diff[1];
    for(int i = 2; i <= N - 1; i++)
        prev_gcd = gcd(prev_gcd, diff[i]);
    printf("%d", diff_sum / prev_gcd - (N - 1));
    return 0;
}