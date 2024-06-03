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
    int n, st;
    scanf("%d%d", &n, &st);
    vector<int> q(n+1), v(n+1), vis(n+1, 1), prev(n+1, 0);
    for(int i=1; i<=n; i++){
        scanf("%d%d", &q[i], &v[i]);
    }
    // que esta pasando aki ?
    int ans = 0, p = 1;
    while(st > 0 && st <= n){
        if(q[st] == 0){
            p = (p > 0 ? -1 : 1) * (abs(p) + v[st]);
        } else {
            if(abs(p) >= v[st]){
                ans += vis[st];
                vis[st] = 0;
            }
        }
        if(prev[st] == p){
            break;
        }
        prev[st] = p;
        st += p;
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
