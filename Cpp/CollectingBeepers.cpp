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
    int a, b; scanf("%d%d", &a, &b);
    int k; scanf("%d", &k);
    if(k == 0){
        puts("0");
        return;
    }
    vector<int> x(k), y(k);
    for(int i=0; i<k; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    vector<int> v(k);
    for(int i=0; i<k; i++) v[i] = i;
    int ans = INT_MAX;
    
    auto getMan = [&] (int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    };
    
    do{
        int dist = getMan(a, b, x[v[0]], y[v[0]]);
        for(int i=0; i<k-1; i++){
            dist += getMan(x[v[i]], y[v[i]], x[v[i+1]], y[v[i+1]]);
        }
        dist += getMan(x[v[k-1]], y[v[k-1]], a, b);
        ans = min(ans, dist);
    } while(next_permutation(all(v)));
    printf("%d\n", ans);
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
