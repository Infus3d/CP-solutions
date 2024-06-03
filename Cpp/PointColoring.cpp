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
    long long a, b;
    scanf("%lld%lld", &a, &b);
    if(!a && !b){
        puts("0");
        return;
    }
    long long thexor = a ^ b;
    long long two = 1LL;
    long long powa = 0LL;
    while(two <= thexor){
        two *= 2LL;
        powa++;
    }
    if(thexor >= min(a, b) && two == thexor + 1){
        printf("%lld\n", powa);
    } else {
        printf("-1\n");
    }
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
