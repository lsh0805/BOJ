#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
int N, M, K, x, y, z, ans, add[10][10], curr[10][10], dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
deque<int> age[10][10];

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            curr[i][j] = 5;
            scanf("%d", &add[j][i]);
        }
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &x, &y, &z);
        age[y - 1][x - 1].push_back(z);
    }
    for(int year = 0; year < K; year++){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                int k = 0;
                for(deque<int>::iterator it = age[i][j].begin(); it != age[i][j].end(); it++, k++){
                    if(curr[i][j] < *it){
                        while(k < age[i][j].size()){
                            curr[i][j] += (age[i][j].back() / 2);
                            age[i][j].pop_back();
                        }
                        break;
                    }else{
                        curr[i][j] -= *it;
                        *it += 1;
                    }
                }
            }
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                curr[i][j] += add[i][j];
                for(deque<int>::iterator it = age[i][j].begin(); it != age[i][j].end(); it++){
                    if(*it % 5 == 0){
                        for(int l = 0; l < 8; l++){
                            int x = j + dx[l], y = i + dy[l];
                            if(x < 0 || x >= N || y < 0 || y >= N) continue;
                            age[y][x].push_front(1);
                        }
                    }
                }
            }
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            ans += age[i][j].size();
    printf("%d", ans);
    return 0;
}