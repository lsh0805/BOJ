#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define fi first
#define se second
typedef pair<int, int> ii;

int m[101][101], R, C, K, r_len = 3, c_len = 3;

void updateLength() {
    int c_max = -1, r_max = -1;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (m[i][j] != 0) {
                r_max = max(r_max, i);
                c_max = max(c_max, j);
            }
        }
    }
    r_len = r_max + 1;
    c_len = c_max + 1;
}

void r_operate() {
    int cnt[101] = {0, };
    vector<ii> v;
    for(int i = 0; i < r_len; i++) {
        for(int j = 0; j < c_len; j++) {
            if(m[i][j] == 0) continue;
            cnt[m[i][j]]++;
        }
        for (int j = 1; j <= 100; j++) {
            if (cnt[j]) 
                v.push_back(make_pair(cnt[j], j));
        }
        sort(v.begin(), v.end());
        int j = 0;
        for(; j < v.size(); j++) {
            if (j * 2 >= 100) break;
            m[i][j * 2] = v[j].se;
            m[i][j * 2 + 1] = v[j].fi;
        }
        j *= 2;
        for (; j < 100; j++) {
            m[i][j] = 0;
        }
        memset(cnt, 0, sizeof(cnt));
        v.clear();
    }
}

void c_operate() {
    int cnt[101] = {0, };
    vector<ii> v;
    for(int j = 0; j < c_len; j++) {
        for(int i = 0; i < r_len; i++) {
            if(m[i][j] == 0) continue;
            cnt[m[i][j]]++;
        }
        for (int i = 1; i <= 100; i++) {
            if (cnt[i]) 
                v.push_back(make_pair(cnt[i], i));
        }
        sort(v.begin(), v.end());
        int i = 0;
        for(; i < v.size(); i++) {
            if (i * 2 >= 100) break;
            m[i * 2][j] = v[i].se;
            m[i * 2 + 1][j] = v[i].fi;
        }
        i *= 2;
        for (; i < 100; i++) {
            m[i][j] = 0;
        }
        memset(cnt, 0, sizeof(cnt));
        v.clear();
    }
}

void print_map() {
    for (int i = 0; i < r_len; i++) {
        for (int j = 0; j < c_len; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void proceed() {
    if (r_len >= c_len)
        r_operate();
    else
        c_operate();
    updateLength();
    // print_map();
}

int main()
{
    IO;
    cin >> R >> C >> K;
    R--, C--, K;
    for (int i = 0; i < r_len; i++) {
        for (int j = 0; j < c_len; j++) {
            cin >> m[i][j];
        }
    }
    int t = 0;
    while(t <= 100 && m[R][C] != K) {
        proceed();
        t++;
    }
    if (t > 100) cout << "-1";
    else cout << t;
    return 0;
}