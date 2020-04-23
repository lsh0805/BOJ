#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int T, N, L, K, p[100001], a[100001];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> N >> L >> K;
        vector<int> left, right;
        for(int i = 0; i < N; i++){
            cin >> p[i] >> a[i];
            if(a[i] > 0)
                right.push_back(L - p[i]);
            else
                left.push_back(p[i]);
        }
        vector<int> v = left;
        v.insert(v.end(), right.begin(), right.end());
        int l = 0, r = N - 1;
        for(int i = 0; i < K; i++){
            int selected = -1;
            if(v[l] > v[r]){
                selected = r--;
            }else if(v[l] < v[r]){
                selected = l++;
            }else{
                if(a[l] < a[r]){
                    selected = l++;
                }else{
                    selected = r--;
                }
            }
            if(i == K-1)
                cout << a[selected] << "\n";
        }
    }
    return 0;
}