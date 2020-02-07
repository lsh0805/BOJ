#include <bits/stdc++.h>

using namespace std;

pair<int, int> arr[26];
int N = 5, r_c[5], c_c[5], num, bingo, l, r;

int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &num);
            arr[num] = make_pair(i, j);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &num);
            int row = arr[num].first, col = arr[num].second;
            if(++r_c[row] == 5) bingo++;
            if(++c_c[col] == 5) bingo++;
            if(row == col && ++l == 5) bingo++;
            if(row == 4 - col && ++r == 5) bingo++;
            if(bingo >= 3){
                printf("%d", (i * N) + j + 1);
                return 0;
            }
        }
    }
}