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
#define sqr(x) ((x) * (x))

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

void solve(){
    long double x, y;
    scanf("%Lf%Lf", &x, &y);
    int n; scanf("%d", &n);
    vector<long double> a(n), b(n);
    long double ans = 0.0;
    vector<long double> distances;
    for(int i=0; i<n; i++){
        scanf("%Lf%Lf", &a[i], &b[i]);
        distances.push_back(sqrtl(sqr(a[i] - x) + sqr(b[i] - y)));
    }
    sort(all(distances));
    for(int i=0; i<n-1; i++){
        ans += distances[i];
    }
    vector<long double> dp(1<<n, MOD);
    dp[0] = 0;
    for(int mask=0; mask<(1<<n); mask++){
        for(int i=0; i<n; i++){
            if(!((mask>>i)&1)){
                for(int j=0; j<n; j++){
                    if(i != j && !((mask>>j)&1)){
                        umin(dp[mask | (1<<i) | (1<<j)], dp[mask] + sqrtl(sqr(a[i] - a[j]) + sqr(b[i] - b[j])));
                    }
                }
            }
        }
    }
    if(n % 2 == 0){
        ans += dp[(1<<n)-1];
    } else {
        long double mini = MOD;
        for(int i=0; i<n; i++){
            umin(mini, dp[((1<<n)-1) ^ (1<<i)] + sqrtl(sqr(a[i] - x) + sqr(b[i] - y)));
        }
        ans += mini;
    }
    printf("%.6Lf\n", ans);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
