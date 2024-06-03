#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

void solve(){
    int n, m;
    cin >> n >> m;
    vector<char> t(n, '#');
    bool ans = true;
    for(int i=0; i<m; i++){
        int idx;
        string s;
        cin >> idx >> s;
        idx--;
        int nn = (int)s.length();
        int until = n;
        for(int j=0; j<nn; j++){
            if(s[j] == '*'){
                until = j+1;
                break;
            }
            if(t[idx + j] != '#' && t[idx + j] != s[j]){
                ans = false;
            }
            t[idx + j] = s[j];
        }
        for(int j=nn-1; j>=until; j--){
            if(t[n - (nn - j)] != '#' && t[n - (nn - j)] != s[j]){
                ans = false;
            }
            t[n - (nn - j)] = s[j];
        }
    }
    for(int i=0; i<n; i++){
        if(t[i] == '#'){
            ans = false;
        }
    }
    if(!ans){
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(char c : t){
            cout << c;
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int testcase = 1;
    cin >> testcase;
    while(testcase--){
        solve();
    }
    return 0;
}
