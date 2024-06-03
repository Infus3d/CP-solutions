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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int n = (int)s.length();
    vector<string> v{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<pair<int, int>> dp(n+1, make_pair(n+n, 0));
    dp[0] = {0, 1};
    for(int i=1; i<=n; i++){
        if(dp[i-1].ff + 1 < dp[i].ff){
            dp[i] = {dp[i-1].ff + 1, dp[i-1].ss};
        } else if(dp[i-1].ff + 1 == dp[i].ff){
            dp[i].ss = (dp[i].ss + dp[i-1].ss) % 9302023;
        }
        // printf("i: %d\ndp[i].ff: %d, dp[i].ss: %d\n", i, dp[i].ff, dp[i].ss);
        for(string t : v){
            if(n-i+1 >= (int)t.length()){
                bool ok = true;
                for(int j=0; j<(int)t.length(); j++){
                    if(s[i+j-1] != t[j]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    auto &nex = dp[i+(int)t.length()-1];
                    if(dp[i-1].ff + 1 < nex.ff) {
                        nex = {dp[i-1].ff + 1, dp[i-1].ss};
                    } else if(nex.ff == dp[i-1].ff + 1){
                        nex.ss = (nex.ss + dp[i-1].ss) % 9302023;
                    }
                    // cout << "i: " << i << " " << "t: " << t << "\n";
                    break;
                }
            }
        }
    }
    printf("%d\n%d\n", dp[n].ff, dp[n].ss);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
