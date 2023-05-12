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

#define sqr(x) ((x) * (x))

void solve(){
    int n, L, W;
    scanf("%d%d%d", &n, &L, &W);
    int half = n / 2;
    vector<int> p(n);
    for(int i=0; i<n; i++){
        scanf("%d", &p[i]);
    }
    sort(all(p));
    vector<vector<double>> dp(half+1, vector<double>(half+1, INFINITY));
    
    double treeDistance = 1.0 * L / (half-1);
    
    auto distLeft = [&](int idx, int x) -> double{
        double goal = treeDistance * (double)(x - 1);
        return abs(goal - p[idx]);
    };
    
    auto distRight = [&](int idx, int x) -> double{
        double goal = treeDistance * (double)(x - 1);
        return sqrt(sqr(goal - p[idx]) + sqr((double)W));
    };
    
    dp[0][0] = 0.0;
    for(int i=0; i<=half; i++){
        for(int j=0; j<=half; j++){
            if(i < half){
                umin(dp[i+1][j], dp[i][j] + distLeft(i+j, i+1));
            }
            if(j < half){
                umin(dp[i][j+1], dp[i][j] + distRight(i+j, j+1));
            }
        }
    }
    printf("%.8lf\n", dp[half][half]);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
