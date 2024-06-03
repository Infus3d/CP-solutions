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
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> w(n), a(n), idx(n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &w[i], &a[i]);
        idx[i] = i;
    }
    sort(all(idx), [&](int x, int y) {
        return w[x] < w[y];
    });
    deque<pair<int, int>> Q;
    Q.push_back({-k, m});
    long long ans = 0;
    for(int i : idx){
        int used = 0;
        while(!Q.empty() && a[i] > 0 && Q.front().first + k <= w[i]){
            auto [ww, aa] = Q.front();
            Q.pop_front();
            if(aa <= a[i]){
                used += aa;
                a[i] -= aa;
            } else {
                used += a[i];
                Q.push_front({ww, aa - a[i]});
                a[i] = 0;
            }
        }
        if(used > 0){
            Q.push_back({w[i], used});
            ans += used;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
