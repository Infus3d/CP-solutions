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

#define sqr(x) ((x) * (x))

void solve(){
    int n; scanf("%d", &n);
    double l = 0.0, r = (double)1e5;
    for(int t=0; t<100; t++){
        double radius = (l + r) / 2;
        long long total = 0;
        for(int j=1; j<=(int)radius; j++){
            total += 4*floor(sqrt(sqr(radius) - sqr(j)));
        }
        if(total > n) r = radius;
        else l = radius;
    }
    printf("%.6lf\n", r);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
