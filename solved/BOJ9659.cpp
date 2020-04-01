#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, pair<int, int>> p2;
typedef vector<int> vi;

long long N;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    if(N % 2){
        cout << "SK";
    }else{
        cout << "CY"
    }
    return 0;
}