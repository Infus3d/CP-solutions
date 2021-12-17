#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day
 
using namespace std;
// using namespace __gnu_pbds;
 
const int N = 1e2+7;
const int M = 600;
const int MOD = 1e8;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n[2], k[2];
int dp[N*2][N][2];

int main(){
    scanf("%d%d%d%d", &n[0], &n[1], &k[0], &k[1]);
    dp[0][0][0] = dp[0][0][1] = 1;
    for(int i=0; i<n[0]+n[1]; i++){
        for(int n1=0; n1<=min(i, n[0]); n1++){
            int n2 = i-n1;
            for(int j=1; j<=min(k[0], n[0]-n1); j++)
                if(i+j <= n[0]+n[1])
                    dp[i+j][n1+j][0] = (dp[i+j][n1+j][0] + dp[i][n1][1]) % MOD;
            
            for(int j=1; j<=min(n[1]-n2, k[1]); j++)
                if(i+j <= n[0]+n[1])
                    dp[i+j][n1][1] = (dp[i+j][n1][1] + dp[i][n1][0]) % MOD;
        }
    }
    printf("%d\n", (dp[n[0]+n[1]][n[0]][0] + dp[n[0]+n[1]][n[0]][1]) % MOD);
	
    return 0;
}
