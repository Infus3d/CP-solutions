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
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    if(n == 1){
        puts("0");
    } else {
        long long L = 0;
        for(int i=0; i<1; i++){
            long long lplus = (a[i] ^ a[i+1]) / 2LL;
            printf("lplus - i: %lld\n", lplus - i);
            L |= (lplus - i);
        }
        for(int i=62; i>=1; i--){
            if((L & (1LL << (i-1))) > 0 && (L & (1LL << i)) == 0LL){
                break;
            }
            if((a[0] & (1LL << i)) > 0){
                L |= (1LL << i);
            }
        }
        printf("%lld\n", (a[0] ^ L));
    }
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
