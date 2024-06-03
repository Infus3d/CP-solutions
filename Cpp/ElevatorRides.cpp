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
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    vector<bool> ok((1<<n), true);
    for(int mask=0; mask<(1<<n); mask++){
        long long cur = 0;
        for(int i=0; i<n; i++){
            if((mask&(1<<i)) > 0){
                cur += a[i];
            }
        }
        if(cur > (long long)x){
            ok[mask] = false;
        }
    }
    vector<int> dp((1<<n), n+1);
    dp[0] = 0;
    long long totalIteratations = 0;
    for(int i=0; i<(1<<n); i++){
        int iterations = 0;
        for(int j=i; j<(1<<n); j=((j+1)|i)){
            if(ok[j&(~i)] && dp[j] > dp[i] + 1){
                dp[j] = dp[i] + 1;
            }
            iterations++;
        }
        totalIteratations += iterations;
    }
    printf("%d\n", dp[(1<<n)-1]);
    printf("total iterations: %lld\n", totalIteratations);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
