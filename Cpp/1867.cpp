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
    int n, k;
    scanf("%d%d", &n, &k);
    int xorsofar = 0;
    for(int i=0; i<n/k; i++){
        printf("? %d\n", (i*k)+1);
        fflush(stdout);
        int a; scanf("%d", &a);
        xorsofar ^= a;
    }
    if(n%k > 0){
        int remaining = 0, a;
        int kk = n%k;
        printf("? %d\n", n-(kk/2)-k+1);
        fflush(stdout);
        scanf("%d", &a);
        remaining ^= a;
        printf("? %d\n", n-k+1);
        fflush(stdout);
        scanf("%d", &a);
        remaining ^= a;
        xorsofar ^= remaining;
    }
    printf("! %d\n", xorsofar);
    fflush(stdout);
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
