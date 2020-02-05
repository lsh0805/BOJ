#include <bits/stdc++.h>

using namespace std;

int N, K, max_value;
string arr[1001];

bool comp(const string& a, const string& b){
    return ((a + b) > (b + a));
}

int main(){
    cin >> K >> N;
    for(int i = 0; i < K; i++){
        cin >> arr[i];
        max_value = max(max_value, stoi(arr[i]));
    }
    sort(arr, arr + K, comp);
    bool flag = false;
    for(int i = 0; i < K; i++){
        cout << arr[i];
        if(!flag && stoi(arr[i]) == max_value){
            for(int i = 0; i < N - K; i++)
                cout << max_value;
            flag = true;
        }
    }
    return 0;
}