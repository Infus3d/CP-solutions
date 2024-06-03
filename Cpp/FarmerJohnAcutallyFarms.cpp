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
    vector<long long> h(n);
    for(int i=0; i<n; i++){
        scanf("%lld", &h[i]);
    }
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    vector<int> t(n);
    vector<int> b(n);
    for(int i=0; i<n; i++){
        scanf("%d", &t[i]);
        b[n-t[i]-1] = i;
    }
    long long mini = 0LL, maxi = (long long)1e18+10LL;
    for(int i=1; i<n; i++){
        int cur = b[i], prev = b[i-1];
        if(a[cur] < a[prev]){
            maxi = min(maxi, (h[cur] - h[prev] - 1) / (a[prev] - a[cur]));
        } else if(a[cur] > a[prev]) {
            if(h[prev] >= h[cur]){
                mini = max(mini, (h[prev] - h[cur]) / (a[cur] - a[prev]) + 1);
            }
        } else {
            if(h[cur] <= h[prev]){
                printf("-1\n");
                return;
            }
        }
        if(mini > maxi){
            printf("-1\n");
            return;
        }
    }
    printf("%lld\n", mini);
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
