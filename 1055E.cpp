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

const int N = 1507;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, s, m, k, arr[N], sum[N];
int dp[N][N], rr[N][N];
int jump[N];
pii seg[N];

int get(int val){
    memset(sum, 0, sizeof(sum));
    memset(jump, -1, sizeof(jump));
    memset(dp, -1, sizeof(dp));
    
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + (arr[i] <= val);
    
    for(int i=1; i<=s; i++)
        for(int j=seg[i].ff; j<=seg[i].ss; j++)
            umax(jump[j], seg[i].ss);
    
    dp[n+1][0] = 0; 
    for(int i=n; i>=1; i--)
        for(int j=m; j>=0; j--){
            dp[i][j] = dp[i+1][j];
            
            if(~jump[i] && j>0 && ~dp[jump[i]+1][j-1])
                umax(dp[i][j], dp[jump[i]+1][j-1] + (sum[jump[i]] - sum[i-1]));
        }
    
    int ret = 0;
    
    for(int j=1; j<=m; j++) umax(ret, dp[1][j]);
    
    return ret;
}

int main(){
    scanf("%d%d%d%d", &n, &s, &m, &k);
    
    for(int i=0; i<n; i++) scanf("%d", arr+i+1);
    for(int i=1; i<=s; i++) scanf("%d%d", &seg[i].ff, &seg[i].ss);
    
    int l = 1, r = MOD-7;
    
    while(l < r){
        if(get(mid(l, r)) >= k)
            r = mid(l, r);
        else
            l = mid(l, r)+1;
    }
    
    if(get(l) >= k) printf("%d\n", l);
    else            printf("-1\n");
    
    return 0;
}

