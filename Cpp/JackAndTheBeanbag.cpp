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
    vector<int> v(n);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    int t; scanf("%d", &t);
    vector<int> farmers;
    for(int i=0; i<t; i++){
        int curFarmer = 0;
        int k; scanf("%d", &k);
        for(int j=0; j<k; j++){
            int a; scanf("%d", &a);
            curFarmer |= (1<<(a-1));
        }
        farmers.push_back(curFarmer);
    }
    int ans = 0;
    for(int mask=0; mask<(1<<n); mask++){
        bool ok = true;
        for(int i=0; i<t; i++){
            if(!(mask & farmers[i])){
                ok = false;
                break;
            }
        }
        if(ok){
            int cur = 0;
            for(int i=0; i<n; i++){
                if(!(mask&(1<<i))){
                    cur += v[i];
                }
            }
            ans = max(ans, cur);
        }
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
