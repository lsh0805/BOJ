#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

string str;

bool check(string str){
    for(int i = 1; i < str.length(); i++)
        if(str[i] == str[i - 1])
            return false;
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> str;
    int ans = 0;
    sort(str.begin(), str.end());
    do{
        ans += check(str);
    }while(next_permutation(str.begin(), str.end()));
    cout << ans;
    return 0;
}