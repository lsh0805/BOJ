#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int T, n;

int main(){
    while(true){
        scanf("%d", &n);
        if(n == - 1) break;
        int sum = 1;
        vector<int> v;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                sum += i;
                v.push_back(i);
                if(i != n / i){
                    sum += n / i;
                    v.push_back(n / i);
                }
            }
        }
        sort(v.begin(), v.end());
        if(sum == n){
            printf("%d = 1 + ", n);
            for(int i = 0; i < v.size() - 1; i++)
                printf("%d + ", v[i]);
            printf("%d\n", v[v.size() - 1]);
        }else{
            printf("%d is NOT perfect.\n", n);
        }
    }
    return 0;
}