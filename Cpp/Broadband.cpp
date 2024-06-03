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
    int n, m, k, s;
    scanf("%d%d%d%d", &n, &m, &k, &s);
    n += m;
    vector<double> a(n+1);
    for(int i=1; i<=n; i++){
        scanf("%lf", &a[i]);
    }
    sort(a.begin()+1, a.end());
    vector<vector<double>> b(n+1, vector<double>(n+1));
    for(int i=1; i<=n; i++){
        double sum = 0, ssum = 0; // sum, and square sum
        for(int j=i; j<=n; j++){
            ssum += a[j] * a[j];
            sum += a[j];
            b[i][j] = ssum - (sum * sum) / (j-i+1);
        }
    }
    vector<vector<double>> dp(n+1, vector<double>(k+1, 1.0 * INT_MAX));
    dp[0][0] = 0;
    for(int r=1; r<=n; r++){
        for(int j=1; j<=min(k, r); j++){
            for(int l=0; l<r; l++){
                umin(dp[r][j], dp[l][j-1] + b[l+1][r]);
            }
        }
    }
    double ans = 1.0 * INT_MAX;
    for(int i=0; i<=k; i++){
        umin(ans, dp[n][i]);
    }
    double half = s / 2.0;
    for(int i=1; i<=n; i++){
        ans += half * half;
    }
    printf("%.5lf\n", ans);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
