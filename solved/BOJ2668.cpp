#include <bits/stdc++.h>

using namespace std;

int N, arr[101], visited[101], ans;
vector<int> track;

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", arr + i);
    for(int i = 1; i <= N; i++){
        int curr = arr[i], cnt = 0;
        bool flag = false;
        vector<int> v;
        while(true){
            if(curr < i || visited[curr] == i) break;
            if(arr[curr] == i) flag = true;
            v.push_back(curr);
            visited[curr] = i;
            curr = arr[curr];
            cnt++;
        }
        if(flag){
            ans += cnt;
            for(int j = 0; j < v.size(); j++)
                track.push_back(v[j]);
        }
    }
    sort(track.begin(), track.end());
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++)
        printf("%d\n", track[i]);
    return 0;
}