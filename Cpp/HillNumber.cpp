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

long long dp[21][11][2][2];

long long rec(int pos, int dig, int fall, int smaller, vector<int> &numba){
    if(pos == sz(numba)){
        return 1LL;
    }
    long long &ret = dp[pos][dig][fall][smaller];
    if(~ret){
        return ret;
    }
    
    ret = 0LL;
    for(int i=(dig == 10); i<=min(9, dig); i++){
        if(i <= numba[pos]){
            ret += rec(pos+1, i, (fall || (dig < 10 && (i < dig))), (smaller || i < numba[pos]), numba);
        }
        if(i > numba[pos] && smaller){
            ret += rec(pos+1, i, (fall || (dig < 10 && (i < dig))), smaller, numba);
        }
    }
    
    if(!fall){
        for(int i=dig+1; i<10; i++){
            if(i <= numba[pos]){
                ret += rec(pos+1, i, fall, (smaller || i < numba[pos]), numba);
            }
            if(i > numba[pos] && smaller){
                ret += rec(pos+1, i, fall, smaller, numba);
            }
        }
    }
    
    return ret;
}

// 69358331

void solve(){
    long long num; scanf("%lld", &num);
    vector<int> numba;
    while(num > 0LL){
        numba.push_back((int)(num % 10LL));
        num /= 10LL;
    }
    reverse(all(numba));
    int n = sz(numba);
    int rise = -1, fall = n;
    for(int i=1; i<sz(numba); i++){
        if(numba[i] < numba[i-1] && fall == n) fall = i;
        if(numba[i] > numba[i-1]) rise = i;
    }
    if(fall < rise){
        puts("-1");
        return;
    }
    memset(dp, -1LL, sizeof(dp));
    long long ans = rec(0, 10, 0, 0, numba);
    numba = vector<int>(n, 9);
    for(int i=1; i<n; i++){
        // numba[i] = 0;
        ans += rec(i, 10, 0, 1, numba);
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
