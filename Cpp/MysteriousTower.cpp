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
    int n; scanf("%d", &n);
    vector<double> p(n);
    for(int i=0; i<n; i++){
        scanf("%lf", &p[i]);
    }
    
    vector<vector<double>> dp(n, vector<double>(2*n+1, 0));
    vector<vector<double>> unit(n, vector<double>(2*n+1, 0));
    auto idx = [&](int x) {
        return (x + n);
    };
    
    unit[0][idx(0)] = 1.0 - p[0];
    unit[0][idx(1)] = p[0];
    
    for(int i=1; i<n; i++){
        dp[i][n] = dp[i-1][n] * (1.0 - p[i]);
        unit[i][n] = unit[i-1][n] * (1.0 - p[i]);
        for(int j=n; j<(n<<1); j++){
            dp[i][j] += (dp[i-1][j+1] + unit[i-1][j+1]) * (1.0 - p[i]);
            unit[i][j] += (1.0 - p[i]) * unit[i-1][j+1];
        }
        for(int j=n+1; j<=(n<<1); j++){
            dp[i][j] += dp[i-1][j-1] * p[i];
            unit[i][j] += unit[i-1][j-1] * p[i];
        }
    }
    double ans = 0.0;
    for(int i=0; i<=(n<<1); i++){
        ans += dp[n-1][i];
    }
    printf("%.6lf\n", ans * 2.0);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
