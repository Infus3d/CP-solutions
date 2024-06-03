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
    int fhalf = (n+1) / 2;
    int shalf = n - fhalf;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    int m, t; scanf("%d%d", &m, &t);
    vector<vector<int>> a(fhalf+1, vector<int>());
    vector<vector<int>> b(shalf+1, vector<int>());
    for(int mask=0; mask<(1<<fhalf); mask++){
        int bitcnt = __builtin_popcount(mask);
        int sum = 0;
        for(int i=0; i<fhalf; i++){
            if((mask>>i)&1){
                sum += v[i];
            }
        }
        a[bitcnt].push_back(sum);
    }
    for(int mask=0; mask<(1<<shalf); mask++){
        int bitcnt = __builtin_popcount(mask);
        int sum = 0;
        for(int i=0; i<shalf; i++){
            int j = i + fhalf;
            if((mask>>i)&1){
                sum += v[j];
            }
        }
        b[bitcnt].push_back(sum);
    }
    for(int i=0; i<=fhalf; i++){
        sort(all(a[i]));
        // for(int h : a[i]) printf("i: %d, h: %d\n", i, h);
    }
    for(int i=0; i<=shalf; i++){
        sort(all(b[i]));
        // for(int h : b[i]) printf("i: %d, h: %d\n", i, h);
    }
    int ans = 0;
    for(int i=0; i<=min(fhalf, m); i++){
        int j = m-i;
        if(j > shalf) continue;
        for(int h : a[i]){
            int rem = t - h;
            int en = upper_bound(all(b[j]), rem) - b[j].begin();
            int st = lower_bound(all(b[j]), rem) - b[j].begin();
            ans += (en - st);
        }
    }
    vector<vector<int>> C(n+1, vector<int>(n+1, 0));
    for(int i=0; i<=n; i++){
        C[i][0] = C[i][i] = 1;
        for(int j=1; j<i; j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    printf("%d : %d\n", ans, C[n][m]-ans);
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    for(int t=0; t<testcase; t++){
        printf("Game %d -- ", t+1);
        solve();
    }
    return 0;
}
