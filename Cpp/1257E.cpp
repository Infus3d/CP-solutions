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

const int N = 2e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int k[4], n, a, pos[N];
int dp[N][4];
set <int> v  = {-1, 1, 1, 2, 4, 12, 12, 144};

int main(){
    //printf("%d\n", *v.lower_bound(145));
    printf("%d\n", *(lower_bound(all(v), 4)));
    
    scanf("%d%d%d", &k[1], &k[2], &k[3]); n = k[1]+k[2]+k[3];
    
    for(int i=1; i<=3; i++)
        for(int j=1; j<=k[i]; j++)
            scanf("%d", &a), pos[a] = i;
            
    
    for(int i=1; i<=n; i++){
        int cur = dp[i][1] = dp[i][2] = dp[i][3] = MOD;
        
        for(int j=1; j<=3; j++){
            umin(cur, dp[i-1][j]);
            umin(dp[i][j], cur+(pos[i] == j ? 0 : 1));
        }
    }
    
    printf("%d\n", min(dp[n][1], min(dp[n][2], dp[n][3])));
    
	return 0;
}

