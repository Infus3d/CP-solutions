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
    long long n, k; scanf("%lld%lld", &n, &k);
    long long ans = 0;
    while(n > k){
        long long curAns = 0;
        long long curn = 1;
        int cnt = 0;
        while(curn*k+1 <= n){
            curAns = curAns*k+1;
            curn = curn*k+1;
            if(++cnt >= k){
                printf("%lld\n", curAns + (n - curn));
                return;
            }
        }
        ans += curAns;
        n -= curn;
    }
    printf("%lld\n", ans);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
