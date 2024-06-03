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
    long long n; scanf("%lld", &n);
    for(int i=10; i<=(int)1e9; i*=10){
        long long special = (i+1);
        long long needed = n / __gcd(n, special);
        long long ans = (((i/10) + needed - 1) / needed) * needed;
        if(i/10 <= ans && ans < i){
            printf("%lld%lld\n", ans, ans);
            return;
        }
    }
    assert(false);
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
