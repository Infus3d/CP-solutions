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
    int k, n, m;
    scanf("%d%d%d", &k, &n, &m);
    n++, m++;
    vector<int> a(n), b(m);
    vector<int> pos(k*k+1, -1);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    vector<int> lcs;
    for(int i=0; i<m; i++){
        scanf("%d", &b[i]);
        if(pos[b[i]] != -1){
            int val = pos[b[i]];
            if(lcs.empty() || lcs.back() < val){
                lcs.push_back(val);
            } else {
                auto it = lower_bound(all(lcs), val);
                assert(it != lcs.end());
                *it = val;
            }
        }
    }
    printf("%d\n", sz(lcs));
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    for(int t=1; t<=testcase; t++){
        printf("Case %d: ", t);
        solve();
    }
    return 0;
}
