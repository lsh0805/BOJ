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

int T, N, ans;

vector<int> getPrime(){
    vector<int> p;
    bool notPrime[1000001] = {0, };
    for(int i = 2; i <= 1000000; i++){
        if(notPrime[i]) continue;
        p.push_back(i);
        if(i >= 1000) continue;
        for (int j = i * i; j <= 1000000; j += i)
            notPrime[j] = true;
    }
    return p;
}

bool checkPalindrome(int num){
    string str = to_string(num);
    for(int i = 0; i < str.size()/2; i++){
        if(str[i] != str[str.size() - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> prime = getPrime();
    cin >> N;
    for(int p : prime){
        if(p >= N && checkPalindrome(p)){
            cout << p;
            return 0;
        }
    }
    cout << 1003001;
    return 0;
}