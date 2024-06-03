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
    vector<int> a(n, -1), b(n, -1), rb(n, -1), c(n);
    for(int i=0; i<k; i++){
        int aa; scanf("%d", &aa);
        a[aa-1] = i;
        c[aa-1] = 1;
    }
    for(int i=0; i<k; i++){
        int bb; scanf("%d", &bb);
        b[bb-1] = i;
        rb[bb-1] = (k - i - 1);
        c[bb-1] = 1;
    }
    vector<int> shiftL(n), shiftR(n);
    for(int i=0; i<n; i++){
        if(c[i]){
            if(~a[i] && ~b[i]){
                shiftL[(b[i] - a[i] + k) % k]++;
            }
            if(~a[i] && ~rb[i]){
                shiftR[(rb[i] - a[i] + k) % k]++;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, shiftL[i]);
        ans = max(ans, shiftR[i]);
    }
    // printf("%d\n", ans);
    for(int i=0; i<n; i++){
        ans += (1 - c[i]);
    }
    printf("%d\n", ans);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
