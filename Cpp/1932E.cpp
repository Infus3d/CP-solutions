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
    int n, m; scanf("%d%d", &n, &m);
    vector<int> a(m), b(m);
    vector<vector<int>> v(n+2, vector<int>());
    vector<vector<int>> h(n+2, vector<int>());
    for(int i=0; i<m; i++){
        scanf("%d%d", &a[i], &b[i]);
        v[a[i]].push_back(b[i]);
        h[b[i]].push_back(a[i]);
    }
    vector<int> dp(n+2, 0);
    int cnt = 0;
    multiset<int> setik;
    for(int i=1; i<=n+1; i++){
        umax(dp[i], dp[i-1]);
        for(int j : v[i]){
            setik.insert(j);
            // printf("%d inserted\n", j);
        }
        cnt += sz(v[i]);
        if(!setik.empty()){
            int maxR = *(--setik.end());
            // printf("%d\n", maxR);
            umax(dp[maxR+1], dp[i] + cnt);
            // printf("i: %d, maxR: %d\n", i, maxR);
        }
        cnt -= sz(h[i]);
        for(int j=0; j<sz(h[i]); j++){
            setik.erase(setik.find(i));
        }
        // printf("i:%d, dp[i]:%d\n", i, dp[i]);
    }
    printf("%d\n", dp[n+1]);
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
