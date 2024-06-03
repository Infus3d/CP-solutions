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
    int n, q, C;
    scanf("%d%d%d", &n, &q, &C);
    vector<int> a(n, 0), maxiA(n, 0);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        maxiA[i] = a[i];
        if(!i && !a[i]){
            a[i] = maxiA[i] = 1;
        }
    }
    vector<int> b(n, -1);
    for(int i=0; i<q; i++){
        int h, v; scanf("%d%d", &h, &v);
        umax(b[v-1], h-1);
    }
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            a[i] = (~b[i] ? maxiA[b[i]] : 0) + 1;
        } else if(~b[i] && a[i] <= maxiA[b[i]]){
            puts("-1");
            return;
        }
        if(i > 0){
            maxiA[i] = max(maxiA[i-1], a[i]);
        }
    }
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    puts("");
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
