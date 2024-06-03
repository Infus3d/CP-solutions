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
    string s;
    // cout << "fhksadjfkls\n";
    while(cin >> s){
        // cout << "HELLO\n";
        int n = (int)s.length();
        vector<vector<bool>> T(n+1, vector<bool>(n+1, false));
        for(int i=0; i<n; i++){
            int l = i, r = i;
            while(l > 0 && r < n-1 && s[l-1] == s[r+1]){
                l--, r++;
                T[l][r] = true;
            }
            l = i-1, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                T[l][r] = true;
                l--, r++;
            }
        }
        set<string> ans;
        for(int i=0; i<n; i++){
            string t = "";
            for(int j=i; j<n; j++){
                t += s[j];
                if(T[i][j]){
                    ans.insert(t);
                }
            }
        }
        for(string t : ans){
            cout << t << "\n";
        }
        cout << "\n";
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
