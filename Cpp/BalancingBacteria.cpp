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
    long long total = 0, negDelta = 0, posDelta = 0, ans = 0;
    for(int i=0; i<n; i++){
        long long a; scanf("%lld", &a);
        long long cur = a + total;
        ans += abs(cur);
        if(cur > 0){
            negDelta += -cur;
            total += -cur;
        } else {
            posDelta += abs(cur);
            total += abs(cur);
        }
        total += (negDelta + posDelta);
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
