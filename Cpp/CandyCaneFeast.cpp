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
    int n, m;
    scanf("%d%d", &n, &m);
    vector<long long> a(n), b(m);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    for(int i=0; i<m; i++){
        scanf("%lld", &b[i]);
        long long maxSoFar = 0;
        for(int j=0; j<n; j++){
            long long canEat = a[j] - maxSoFar;
            if(b[i] < canEat){
                a[j] += b[i];
                break;
            } else if(canEat > 0){
                maxSoFar = max(maxSoFar, a[j]);
                b[i] -= canEat;
                a[j] += canEat;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%lld\n", a[i]);
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
