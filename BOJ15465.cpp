#include <bits/stdc++.h>

using namespace std;

string name, diff;
int N, day, d, ans, milk[3] = {7, 7, 7}, before[3] = {1, 1, 1}, idx, max_milk;
vector<pair<int, pair<int, int>>> v;

bool compare(const pair<string, int> &p1, const pair<string, int> &p2){
    return p1.second >= p2.second;
}

int main(){
    cin >> N;
    while(N--){
        cin >> day >> name >> diff;
        if(name == "Bessie")
            idx = 0;
        else if(name == "Elsie")
            idx = 1;
        else
            idx = 2;
        v.push_back(make_pair(day, make_pair((diff[1] - '0') * (diff[0] == '+' ? 1:-1), idx)));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        milk[v[i].second.second] += v[i].second.first;
        max_milk = max({milk[0], milk[1], milk[2]});
        bool flag = false;
        for(int j = 0; j < 3; j++)
            if(before[j] && max_milk > milk[j]){
                flag = true;
                before[j] = 0;
            }else if(!before[j] && max_milk == milk[j]){
                flag = true;
                before[j] = 1;
            }
        ans += flag;
    }
    cout << ans;
    return 0;
}