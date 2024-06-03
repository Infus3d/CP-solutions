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
    vector<int> a(n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    vector<int> P(15000, 0);
    P[0] = P[1] = 1;
    for(int i=2; i<15000; i++){
        if(!P[i]){
            for(int j=i+i; j<15000; j+=i){
                P[j] = 1;
            }
        }
    }
    vector<int> cost((1<<n), 0);
    for(int mask=0; mask<(1<<n); mask++){
        int num = 0;
        for(int i=0; i<n; i++){
            if(((mask>>i)&1)){
                num += a[i];
            }
        }
        for(int i=2; i*i<=num; i++){
            if(num % i == 0){
                if(!P[i]) cost[mask]++;
                if(i*i != num && !P[num/i]) cost[mask]++;
            }
        }
        if(!P[num]) cost[mask]++;
    }
    vector<int> dp((1<<n), 0);
    for(int mask=0; mask<(1<<n); mask++){
        for(int nmask=mask; nmask<(1<<n); nmask=((nmask+1)|mask)){
            int &c = cost[(nmask&(~mask))];
            if(dp[nmask] < dp[mask] + c){
                dp[nmask] = dp[mask] + c;
            }
        }
    }
    printf("%d\n", dp[(1<<n)-1]);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
