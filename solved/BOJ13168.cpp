#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int N, R, M, K, a, b, dest[201];
double c, cost[101][101][2];
const double INF = 1e9;
string str, str1, str2;
unordered_map<string, int> m;
unordered_map<string, double> sale;

double floyd(bool b){
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++){
            if(cost[i][k][b] == INF) continue;
            for(int j = 0; j < N; j++){
                cost[i][j][b] = min(cost[i][j][b], cost[i][k][b] + cost[k][j][b]);
            }
        }
    double ret = 0;
    for(int i = 0; i < M - 1; i++)
        ret += cost[dest[i]][dest[i + 1]][b];
    return ret + R * b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> R;
    for(int i = 0; i < N; i++){
        cin >> str;
        m[str] = i;
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < 2; k++)
                cost[i][j][k] = INF;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> str;
        dest[i] = m[str];
    }
    cin >> K;
    sale["Mugunghwa"] = 0, sale["ITX-Saemaeul"] = 0, sale["ITX-Cheongchun"] = 0;
    sale["S-Train"] = 0.5, sale["V-Train"] = 0.5;
    sale["Taxi"] = 1, sale["Subway"] = 1, sale["Bus"] = 1, sale["Airplane"] = 1, sale["KTX"] = 1;
    for(int i = 0; i < K; i++){
        cin >> str >> str1 >> str2 >> c;
        a = m[str1], b = m[str2];
        cost[a][b][0] = min(cost[a][b][0], c);
        cost[b][a][0] = min(cost[b][a][0], c);
        cost[a][b][1] = min(cost[a][b][1], c * sale[str]);
        cost[b][a][1] = min(cost[b][a][1], c * sale[str]);
    }
    cout << ((floyd(true) < floyd(false)) ? "Yes\n" : "No\n");
}