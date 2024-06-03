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

long long d[33][33];

void solve(){
    long long n, k;
    scanf("%lld%lld", &n, &k);
    int idx = 0;
    while(idx < 33 && d[k][idx] < n){
        idx++;
    }
    if(idx <= 32){
        printf("%d\n", idx);
    } else {
        puts("Impossible");
    }
}

int main(){
    for(int i=0; i<33; i++){
        d[1][i] = i;
    }
    for(int i=2; i<33; i++){
        for(int j=1; j<33; j++){
            d[i][j] = d[i-1][j-1] + d[i][j-1] + 1;
        }
    }
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
