/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

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
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day

using namespace std;
using namespace __gnu_pbds;

const int N = 3e2+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int binC[N][N], dp[N][N], n, k;
int pow0[N], pow1[N];

int mult(int x, int y){
    return int((1LL * x * y) % MOD);
}

int add(int x, int y){
    return int((0LL + x + y + MOD) % MOD);
}

int main(){
    scanf("%d%d", &n, &k);
    
    for(int i=0; i<=n; i++) binC[i][0] = binC[i][i] = 1;
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            binC[i][j] = add(binC[i-1][j-1], binC[i-1][j]);
    
    pow0[0] = pow1[0] = 1;
    for(int i=1; i<=n; i++){
        pow0[i] = mult(pow0[i-1], k);
        pow1[i] = mult(pow1[i-1], k-1);
    }
    
    dp[0][0] = 1;
    for(int i=1; i<=n; i++)
        dp[i][0] = mult(add(pow0[n], -pow1[n]), dp[i-1][0]);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int passs = mult(dp[i-1][j], mult(add(pow0[n-j], -pow1[n-j]), pow1[j]));
            int filll = 0;
            
            for(int j0=1; j0<=j; j0++)
                filll = add(filll, mult(dp[i-1][j-j0], mult(binC[j][j0], pow1[j-j0])));
            filll = mult(filll, pow0[n-j]);
            
            dp[i][j] = add(passs, filll);
        }
    }
    
    printf("%d\n", dp[n][n]);
    
    return 0;
}

