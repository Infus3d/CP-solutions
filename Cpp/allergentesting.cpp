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
    long long n, d;
    scanf("%lld%lld", &n, &d);
    if(n == 1){
        puts("0");
        return;
    }
    long long cur = 1LL;
    for(int i=1; i<=60; i++){
        if((n/cur)+1 >= (d+1)) cur *= (d+1);
        else cur = n;
        if(cur >= n){
            printf("%d\n", i);
            return;
        }
    }
    puts("0");
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
