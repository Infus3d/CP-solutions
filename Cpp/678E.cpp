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

const int N = 20;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

double dp[N][(1<<18)+7], table[N][N];
int vis[N][(1<<18)+7];
int n;

double rec(int x, int mask){
    if(x == 0){
        double a = 1.0;
        
        for(int i=1; i<n; i++)
            if((mask&(1<<i)))
                a *= table[0][i];
        
        return a;
    }
    
    if(!(mask&1))   return 0.0;
    if(__builtin_popcount(mask) == 1)   return 1.0;
    
    if(vis[x][mask] != -1)
        return dp[x][mask];
    vis[x][mask] = 1;
    
    for(int i=0; i<n; i++)
        if(i != x && (mask & (1<<i)))
            umax(dp[x][mask], rec(x, mask^(1<<i)) * table[x][i] + rec(i, mask^(1<<x)) * table[i][x]);
    
    return dp[x][mask];
}

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%lf", &table[i][j]);
    
    memset(vis, -1, sizeof(vis));
    double ans = 0.0;
    
    for(int i=0; i<n; i++)
        umax(ans, rec(i, (1<<n)-1));
    
    printf("%.6lf\n", ans);
    
	return 0;
}

