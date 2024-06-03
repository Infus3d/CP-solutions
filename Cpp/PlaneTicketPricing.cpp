#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)  x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> p;
    vector<vector<int>> t;
    for(int i=0; i<=m; i++){
        int k; scanf("%d", &k);
        p.push_back(vector<int>(k, 0));
        t.push_back(vector<int>(k, 0));
        for(int j=0; j<k; j++){
            scanf("%d", &p[i][j]);
        }
        for(int j=0; j<k; j++){
            scanf("%d", &t[i][j]);
        }
    }
    // now what?
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    vector<vector<int>> extraHassle(m+1, vector<int>(n+1, MOD));
    for(int j=0; j<sz(t[0]); j++){
        int tleft = max(0, n - t[0][j]);
        int alternative = min(n, t[0][j]) * p[0][j];
        if(dp[0][tleft] < alternative){
            dp[0][tleft] = alternative;
            extraHassle[0][tleft] = p[0][j];
        } else if(dp[0][tleft] == alternative){
            extraHassle[0][tleft] = min(extraHassle[0][tleft], p[0][j]);
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<sz(t[i]); k++){
                int tleft = max(0, j - t[i][k]);
                if(dp[i-1][j] != -1){
                    int alternative = dp[i-1][j] + min(j, t[i][k]) * p[i][k];
                    if(dp[i][tleft] < alternative){
                        dp[i][tleft] = alternative;
                        extraHassle[i][tleft] = extraHassle[i-1][j];
                    } else if(dp[i][tleft] == alternative){
                        extraHassle[i][tleft] = min(extraHassle[i][tleft], extraHassle[i-1][j]);
                    }
                }
            }
        }
    }
    int ans1 = 0, ans2 = MOD;
    for(int i=0; i<=n; i++){
        if(ans1 < dp[m][i]){
            ans1 = dp[m][i];
            ans2 = extraHassle[m][i];
        } else if(ans1 == dp[m][i]){
            ans2 = min(ans2, extraHassle[m][i]);
        }
    }
    printf("%d\n%d\n", ans1, ans2);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
