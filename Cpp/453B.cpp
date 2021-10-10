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

const int N = 1e2+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int dp[N][(1<<17)+2], track[N][(1<<17)+2];
vector <int> primes;
int a[N], b[N], n, bits[62];
int ans = MOD;
int last;

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) scanf("%d", a+i);
    
    for(int i=2; i<60; i++){
        bool prime = 1;
        
        for(int j=2; j*j<=i; j++)
            if(i % j == 0)
                prime = 0;
        
        if(prime)
            primes.pb(i);
    }
    
    for(int i=1; i<60; i++)
        for(int j=0; j<sz(primes); j++)
            if(i % primes[j] == 0)
                bits[i] |= (1<<j);
    
    for(int i=0; i<=n; i++)
        for(int j=0; j<(1<<17); j++)
            dp[i][j] = MOD;
    
    dp[0][0] = 0;    
    for(int i=1; i<=n; i++)
        for(int j=1; j<60; j++)
            for(int k=0; k<(1<<17); k++)
                if(!(k&bits[j]))
                    if(dp[i][k|bits[j]] > dp[i-1][k] + abs(a[i]-j)){
                        dp[i][k|bits[j]] = dp[i-1][k] + abs(a[i]-j);
                        track[i][k|bits[j]] = j;
                    }
    
    for(int i=0; i<(1<<17); i++){
        if(ans > dp[n][i]){
            ans = dp[n][i];
            last = i;
        }
    }
    
    for(int i=n; i>=1; i--){
        b[i] = track[i][last];
        last ^= bits[track[i][last]];
    }
    
    for(int i=1; i<=n; i++)
        printf("%d ", b[i]);
    puts("");
    
	return 0;
}

