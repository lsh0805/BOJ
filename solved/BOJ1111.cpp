#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, S, arr[51], ans, flag;

bool check(int a, int b){
    for(int i = 1; i < N; i++)
        if(arr[i] != arr[i - 1] * a + b)
            return false;
    return true;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    if(N == 1){
        cout << "A";
        return 0;
    }else if(N == 2){
        if(arr[0] == arr[1]){
            cout << arr[0];
            return 0;
        }else{
            cout << "A";
            return 0;
        }
    }else{\
        // y = ax + b
        int a = 0, b = 0;
        if(arr[1] == arr[0])
            a = 1;
        else{
            a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
            b = arr[1] - a * arr[0];
        }
        for(int i = 1; i < N; i++)
            if(arr[i] != arr[i - 1] * a + b){
                cout << "B";
                return 0;
            }
        cout << arr[N - 1] * a + b;
    }
    return 0;
}